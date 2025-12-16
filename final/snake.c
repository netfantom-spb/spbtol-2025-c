#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Добавляем необходимые заголовки для кросс-платформенности
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>  // Для usleep
#endif

// Размеры игрового поля
#define WIDTH 80
#define HEIGHT 20
#define MAX_SNAKE_LENGTH 100

// Структура для координат
typedef struct {
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
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Пауза на миллисекунды (кросс-платформенная)
void sleep_ms(int milliseconds) {
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

int kbhit(void) {
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

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
#endif

// Инициализация игры
void init_game() {
    // Инициализация змейки (начальная длина 3)
    snake_length = 3;
    for (int i = 0; i < snake_length; i++) {
        snake[i].x = WIDTH / 2 - i;
        snake[i].y = HEIGHT / 2;
    }
    
    // Начальное направление
    direction = 'd'; // вправо
    
    // Генерация первой еды
    srand(time(NULL));
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HEIGHT - 2) + 1;
    
    score = 0;
    game_over = 0;
}

// Отрисовка игрового поля
void draw() {
    clear_screen();
    
    // Верхняя граница
    printf("=== ЗМЕЙКА ===\n");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
    
    // Игровое поле
    for (int y = 0; y < HEIGHT; y++) {
        printf("#"); // Левая граница
        for (int x = 0; x < WIDTH; x++) {
            int is_snake = 0;
            
            // Проверка, является ли позиция частью змейки
            for (int i = 0; i < snake_length; i++) {
                if (snake[i].x == x && snake[i].y == y) {
                    if (i == 0)
                        printf("O"); // Голова
                    else
                        printf("o"); // Тело
                    is_snake = 1;
                    break;
                }
            }
            
            // Если это еда
            if (!is_snake && x == food.x && y == food.y) {
                printf("X");
            }
            // Если пустая клетка
            else if (!is_snake) {
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
    printf("Управление: WASD - движение, Q - выход\n");
}

// Обработка ввода с клавиатуры
void input() {
    // Очистка буфера ввода для кросс-платформенности
    #ifdef __linux__
        if (kbhit()) {
            char key = getchar();
            // Игнорируем Enter
            if (key == '\n') return;
            
            switch(key) {
                case 'w':
                case 'W':
                    if (direction != 's') direction = 'w';
                    break;
                case 's':
                case 'S':
                    if (direction != 'w') direction = 's';
                    break;
                case 'a':
                case 'A':
                    if (direction != 'd') direction = 'a';
                    break;
                case 'd':
                case 'D':
                    if (direction != 'a') direction = 'd';
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
        if (scanf(" %c", &key) == 1) {
            switch(key) {
                case 'w':
                case 'W':
                    if (direction != 's') direction = 'w';
                    break;
                case 's':
                case 'S':
                    if (direction != 'w') direction = 's';
                    break;
                case 'a':
                case 'A':
                    if (direction != 'd') direction = 'a';
                    break;
                case 'd':
                case 'D':
                    if (direction != 'a') direction = 'd';
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
void update() {
    // Сохраняем старую голову
    Point old_head = snake[0];
    
    // Перемещаем голову в зависимости от направления
    switch(direction) {
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
        snake[0].y < 0 || snake[0].y >= HEIGHT) {
        game_over = 1;
        return;
    }
    
    // Проверка столкновения с собой
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            game_over = 1;
            return;
        }
    }
    
    // Двигаем тело змейки
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i-1];
    }
    
    // Если голова достигла еды
    if (snake[0].x == food.x && snake[0].y == food.y) {
        // Увеличиваем змейку
        snake[snake_length] = old_head;
        snake_length++;
        
        // Увеличиваем счет
        score += 10;
        
        // Генерируем новую еду
        int food_on_snake;
        do {
            food_on_snake = 0;
            food.x = rand() % (WIDTH - 2) + 1;
            food.y = rand() % (HEIGHT - 2) + 1;
            
            for (int i = 0; i < snake_length; i++) {
                if (food.x == snake[i].x && food.y == snake[i].y) {
                    food_on_snake = 1;
                    break;
                }
            }
        } while (food_on_snake);
    }
}

// Ожидание нажатия клавиши (кросс-платформенное)
void wait_for_key() {
    printf("Нажмите любую клавишу для продолжения...\n");
    #ifdef __linux__
        system("read -n 1 -s");
    #else
        system("pause > nul");
    #endif
}

// Главная функция игры
void snake_game() {
    clear_screen();
    printf("=== ЗМЕЙКА ===\n");
    printf("Цель: управляйте змейкой с помощью клавиш WASD\n");
    printf("Собирайте еду (X) чтобы расти и увеличивать счет\n");
    printf("Игра заканчивается при столкновении с границей или с собой\n");
    printf("\nНажмите Enter для начала...\n");
    
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    
    init_game();
    
    // Основной игровой цикл
    while (!game_over) {
        draw();
        
        #ifdef __linux__
            // Для Linux - проверка ввода без блокировки
            input();
            update();
            sleep_ms(200);
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
int main() {
    int choice;
    char input_buffer[100];
    
    do {
        clear_screen();
        printf("=== ГЛАВНОЕ МЕНЮ ===\n");
        printf("1. Начать игру\n");
        printf("2. Правила игры\n");
        printf("3. Выход\n");
        printf("Выберите пункт (1-3): ");
        
        if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
            if (sscanf(input_buffer, "%d", &choice) == 1) {
                switch(choice) {
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
                        printf("\n3. Особенности:\n");
                        printf("   - Змейка постоянно двигается\n");
                        printf("   - Нельзя двигаться в противоположном направлении\n");
                        printf("   - Игра заканчивается при столкновении\n");
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