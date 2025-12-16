#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Добавляем необходимые заголовки для кросс-платформенности
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h> // Для usleep
#endif

// Размеры игрового поля
#define WIDTH 80
#define HEIGHT 20
#define MAX_SNAKE_LENGTH 100

// Параметры задержки и скорости
#define BASIC_DELAY 200           // Базовая задержка в миллисекундах
#define HORIZONTAL_DELAY_KOEF 1.0 // Коэффициент для горизонтального движения
#define VERTICAL_DELAY_KOEF 1.65  // Коэффициент для вертикального движения
#define DELAY_LENGTH_KOEF 0.9     // Коэффициент уменьшения задержки при удвоении длины
#define LENGTH_CHECKPOINT 2       // Начальная длина для отслеживания удвоений
#define MIN_DELAY 50              // Минимальная задержка (чтобы игра не стала слишком быстрой)

// Структура для координат
typedef struct
{
    int x;
    int y;
} Point;

// Глобальные переменные
Point snake[MAX_SNAKE_LENGTH];
int snake_length;
Point food;
int score;
int game_over;
char direction;

// Очистка экрана (кросс-платформенная)
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Пауза на миллисекунды (кросс-платформенная)
void sleep_ms(int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    // Для Linux/Mac используем usleep (микросекунды)
    usleep(milliseconds * 1000);
#endif
}

// Функция для проверки доступности kbhit/getch
#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
#endif

// Инициализация игры
void init_game()
{
    // Инициализация змейки (начальная длина 2)
    snake_length = 2;
    int start_x = WIDTH / 2;
    int start_y = HEIGHT / 2;

    // Располагаем змейку горизонтально: голова справа, тело слева
    for (int i = 0; i < snake_length; i++)
    {
        snake[i].x = start_x - i; // Голова будет в start_x, затем тело слева
        snake[i].y = start_y;
    }

    // Начальное направление - вправо
    direction = 'd';

    // Генерация первой еды
    srand(time(NULL));

    // Убедимся, что еда не появляется на змейке
    int valid_food = 0;
    while (!valid_food)
    {
        valid_food = 1;
        food.x = rand() % (WIDTH - 2) + 1;
        food.y = rand() % (HEIGHT - 2) + 1;

        // Проверяем, не появилась ли еда на змейке
        for (int i = 0; i < snake_length; i++)
        {
            if (food.x == snake[i].x && food.y == snake[i].y)
            {
                valid_food = 0;
                break;
            }
        }
    }

    score = 0;
    game_over = 0;
}

// Получить задержку в зависимости от направления и длины змейки
int get_delay()
{
    float delay_multiplier = 1.0;
    float base_delay;

    // Вычисляем, сколько раз длина змейки превысила начальную длину в 2 раза
    int doubling_count = 0;
    int checkpoint = LENGTH_CHECKPOINT;

    while (snake_length >= checkpoint * 2)
    {
        doubling_count++;
        checkpoint *= 2;
    }

    // Применяем коэффициент уменьшения за каждое удвоение
    for (int i = 0; i < doubling_count; i++)
    {
        delay_multiplier *= DELAY_LENGTH_KOEF;
    }

    // Базовую задержку умножаем на коэффициент направления
    if (direction == 'w' || direction == 's')
    {
        // Вертикальное движение
        base_delay = BASIC_DELAY * VERTICAL_DELAY_KOEF;
    }
    else
    {
        // Горизонтальное движение
        base_delay = BASIC_DELAY * HORIZONTAL_DELAY_KOEF;
    }

    // Применяем коэффициент уменьшения из-за длины змейки
    int final_delay = (int)(base_delay * delay_multiplier);

    // Минимальная задержка (чтобы игра не стала слишком быстрой)
    if (final_delay < MIN_DELAY)
    {
        final_delay = MIN_DELAY;
    }

    return final_delay;
}

// Отрисовка игрового поля
void draw()
{
    clear_screen();

    // Верхняя граница
    printf("=== ЗМЕЙКА ===\n");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    // Игровое поле
    for (int y = 0; y < HEIGHT; y++)
    {
        printf("#"); // Левая граница
        for (int x = 0; x < WIDTH; x++)
        {
            int is_snake = 0;
            int is_head = 0;
            int snake_index = -1;

            // Проверка, является ли позиция частью змейки
            for (int i = 0; i < snake_length; i++)
            {
                if (snake[i].x == x && snake[i].y == y)
                {
                    is_snake = 1;
                    snake_index = i;
                    if (i == 0)
                    {
                        is_head = 1;
                    }
                    break;
                }
            }

            // Если это голова змейки
            if (is_snake && is_head)
            {
                printf("O");
            }
            // Если это тело змейки
            else if (is_snake)
            {
                // Проверяем, является ли этот сегмент видимым
                // (иногда сегменты могут накладываться при старте)
                printf("o");
            }
            // Если это еда
            else if (x == food.x && y == food.y)
            {
                printf("X");
            }
            // Если пустая клетка
            else
            {
                printf(" ");
            }
        }
        printf("#\n"); // Правая граница
    }

    // Нижняя граница
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n\n");

    // Вывод счета
    printf("Счет: %d\n", score);
    printf("Длина: %d (задержка: %d мс)\n", snake_length, get_delay());
    printf("Управление: WASD - движение, Q - выход\n");
    printf("Текущее направление: %c\n", direction);

// Для отладки - показать координаты змейки
#ifdef DEBUG
    printf("\nОтладка - координаты змейки:\n");
    for (int i = 0; i < snake_length; i++)
    {
        printf("  [%d]: x=%d, y=%d\n", i, snake[i].x, snake[i].y);
    }
#endif
}

// Обработка ввода с клавиатуры
void input()
{
// Очистка буфера ввода для кросс-платформенности
#ifdef __linux__
    if (kbhit())
    {
        char key = getchar();
        // Игнорируем Enter
        if (key == '\n')
            return;

        switch (key)
        {
        case 'w':
        case 'W':
            if (direction != 's')
                direction = 'w';
            break;
        case 's':
        case 'S':
            if (direction != 'w')
                direction = 's';
            break;
        case 'a':
        case 'A':
            if (direction != 'd')
                direction = 'a';
            break;
        case 'd':
        case 'D':
            if (direction != 'a')
                direction = 'd';
            break;
        case 'q':
        case 'Q':
            game_over = 1;
            break;
        }
    }
#else
    // Для Windows используем стандартный ввод
    char key;
    if (scanf(" %c", &key) == 1)
    {
        switch (key)
        {
        case 'w':
        case 'W':
            if (direction != 's')
                direction = 'w';
            break;
        case 's':
        case 'S':
            if (direction != 'w')
                direction = 's';
            break;
        case 'a':
        case 'A':
            if (direction != 'd')
                direction = 'a';
            break;
        case 'd':
        case 'D':
            if (direction != 'a')
                direction = 'd';
            break;
        case 'q':
        case 'Q':
            game_over = 1;
            break;
        }
    }
#endif
}

// Обновление логики игры
void update()
{
    // Сохраняем старую позицию хвоста (для увеличения змейки при поедании еды)
    Point old_tail = snake[snake_length - 1];

    // Двигаем тело змейки СНАЧАЛА, начиная с хвоста
    for (int i = snake_length - 1; i > 0; i--)
    {
        snake[i] = snake[i - 1];
    }

    // Теперь перемещаем голову в зависимости от направления
    switch (direction)
    {
    case 'w': // Вверх
        snake[0].y--;
        break;
    case 's': // Вниз
        snake[0].y++;
        break;
    case 'a': // Влево
        snake[0].x--;
        break;
    case 'd': // Вправо
        snake[0].x++;
        break;
    }

    // Проверка столкновения с границами
    if (snake[0].x < 0 || snake[0].x >= WIDTH ||
        snake[0].y < 0 || snake[0].y >= HEIGHT)
    {
        game_over = 1;
        return;
    }

    // Проверка столкновения с собой (начиная с 1, чтобы не проверять голову с самой собой)
    for (int i = 1; i < snake_length; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            game_over = 1;
            return;
        }
    }

    // Если голова достигла еды
    if (snake[0].x == food.x && snake[0].y == food.y)
    {
        // Увеличиваем змейку, добавляя новый сегмент на место старого хвоста
        snake[snake_length] = old_tail;
        snake_length++;

        // Увеличиваем счет
        score += 10;

        // Генерируем новую еду
        int food_on_snake;
        do
        {
            food_on_snake = 0;
            food.x = rand() % (WIDTH - 2) + 1;
            food.y = rand() % (HEIGHT - 2) + 1;

            for (int i = 0; i < snake_length; i++)
            {
                if (food.x == snake[i].x && food.y == snake[i].y)
                {
                    food_on_snake = 1;
                    break;
                }
            }
        } while (food_on_snake);
    }
}

// Ожидание нажатия клавиши (кросс-платформенное)
void wait_for_key()
{
    printf("Нажмите любую клавишу для продолжения...\n");
#ifdef __linux__
    system("read -n 1 -s");
#else
    system("pause > nul");
#endif
}

// Главная функция игры
void snake_game()
{
    clear_screen();
    printf("=== ЗМЕЙКА ===\n");
    printf("Цель: управляйте змейкой с помощью клавиш WASD\n");
    printf("Собирайте еду (X) чтобы расти и увеличивать счет\n");
    printf("Игра заканчивается при столкновении с границей или с собой\n");
    printf("\nОсобенности:\n");
    printf("- Скорость адаптируется: вертикаль медленнее горизонтали\n");
    printf("- Чем длиннее змейка, тем быстрее она двигается\n");
    printf("- При каждом удвоении длины задержка уменьшается на 10%%\n");
    printf("\nНажмите Enter для начала...\n");

    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    init_game();

    // Основной игровой цикл
    while (!game_over)
    {
        draw();

#ifdef __linux__
        // Для Linux - проверка ввода без блокировки
        input();
        update();
        sleep_ms(get_delay()); // Используем адаптивную задержку
#else
        // Для других систем - посимвольный ввод
        printf("Введите команду (WASD): ");
        input();
        update();
#endif
    }

    // Конец игры
    clear_screen();
    printf("=== ИГРА ОКОНЧЕНА ===\n");
    printf("Ваш счет: %d\n", score);
    printf("Длина змейки: %d\n", snake_length);
    printf("\nНажмите Enter для возврата в меню...\n");

    fgets(buffer, sizeof(buffer), stdin);
}

// Главное меню
int main()
{
    int choice;
    char input_buffer[100];

    do
    {
        clear_screen();
        printf("=== ГЛАВНОЕ МЕНЮ ===\n");
        printf("1. Начать игру\n");
        printf("2. Правила игры\n");
        printf("3. Выход\n");
        printf("Выберите пункт (1-3): ");

        if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL)
        {
            if (sscanf(input_buffer, "%d", &choice) == 1)
            {
                switch (choice)
                {
                case 1:
                    snake_game();
                    break;
                case 2:
                    clear_screen();
                    printf("=== ПРАВИЛА ИГРЫ ===\n");
                    printf("1. Управление змейкой:\n");
                    printf("   W - движение вверх\n");
                    printf("   S - движение вниз\n");
                    printf("   A - движение влево\n");
                    printf("   D - движение вправо\n");
                    printf("   Q - выход из игры\n");
                    printf("\n2. Цель игры:\n");
                    printf("   - Собирайте еду (X) для роста змейки\n");
                    printf("   - Каждая съеденная еда дает +10 очков\n");
                    printf("   - Избегайте столкновений с границами и собой\n");
                    printf("\n3. Особенности скорости:\n");
                    printf("   - Вертикальное движение медленнее (т.к. символы выше чем шире)\n");
                    printf("   - Горизонтальная задержка: %d мс\n", (int)(BASIC_DELAY * HORIZONTAL_DELAY_KOEF));
                    printf("   - Вертикальная задержка: %d мс\n", (int)(BASIC_DELAY * VERTICAL_DELAY_KOEF));
                    printf("   - При удвоении длины задержка умножается на %.1f\n", DELAY_LENGTH_KOEF);
                    printf("   - Минимальная задержка: %d мс\n", MIN_DELAY);
                    printf("   - Начальная длина: %d\n", LENGTH_CHECKPOINT);
                    printf("\nПример удвоений длины:\n");
                    printf("   Длина 3-5: базовая скорость\n");
                    printf("   Длина 6-11: скорость × %.1f\n", DELAY_LENGTH_KOEF);
                    printf("   Длина 12-23: скорость × %.2f\n", DELAY_LENGTH_KOEF * DELAY_LENGTH_KOEF);
                    printf("   И так далее...\n");
                    printf("\nНажмите Enter для возврата в меню...\n");
                    fgets(input_buffer, sizeof(input_buffer), stdin);
                    break;
                case 3:
                    printf("Выход из программы...\n");
                    break;
                default:
                    printf("Неверный выбор! Попробуйте снова.\n");
                    sleep_ms(1000);
                }
            }
        }
    } while (choice != 3);

    return 0;
}