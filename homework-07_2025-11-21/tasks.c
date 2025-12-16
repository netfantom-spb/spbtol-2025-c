#include <stdio.h>
#include <string.h>

// ==================== 1. Подсчет гласных ====================
void task1()
{
    char text[] = "education";
    char *p = text;
    int vowels = 0;

    while (*p != '\0')
    {
        char c = *p;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vowels++;
        }
        p++;
    }

    printf("1. Гласных в \"%s\": %d\n", text, vowels);
}

// ==================== 2. Разница адресов ====================
void task2()
{
    int arr[] = {100, 200, 300, 400};

    // Получаем указатели на элементы массива
    int *ptr0 = &arr[0];
    int *ptr3 = &arr[3];

    long diff_elements = ptr3 - ptr0;              // Разность указателей даёт количество элементов между ними
    long diff_bytes = (char *)ptr3 - (char *)ptr0; // Разница в байтах при приведении к char * (т.к. char = 1 байт), или (ptr3 - ptr0) * sizeof(int);

    printf("2. Адрес arr[0]: %p\n", (void *)ptr0);
    printf("   Адрес arr[3]: %p\n", (void *)ptr3);
    printf("Разница в элементах: %ld\n", diff_elements);
    printf("Разница в байтах: %ld\n", diff_bytes);
}

// ==================== 3. Подстрока ====================
void task3()
{
    char s[] = "programming";
    char *p = s + 3; // 4-й символ (индексация с 0)

    printf("3. Строка: \"%s\"\n", s);
    printf("   Подстрока с 4-го символа: \"%s\"\n", p);
}

// ==================== 4. Последнее вхождение символа ====================
void task4()
{
    char str[] = "abracadabra";
    char *p = str + strlen(str) - 1; // Указатель на последний символ
    char *last_a = NULL;
    int index = -1;

    while (p >= str)
    {
        if (*p == 'a')
        {
            last_a = p;
            index = p - str;
            break;
        }
        p--;
    }

    printf("4. Строка: \"%s\"\n", str);
    if (last_a != NULL)
    {
        printf("   Последнее 'a' по адресу: %p\n", last_a);
        printf("   Индекс: %d\n", index);
    }
    else
    {
        printf("   Символ 'a' не найден\n");
    }
}

// ==================== 5. Указатели ====================
void task5()
{
    int data[] = {1, 2, 3, 4, 5};
    int *p1 = &data[1];
    int *p4 = &data[4];

    printf("5. Адрес data[1]: %p\n", p1);
    printf("   Адрес data[4]: %p\n", p4);
    printf("   Разница (в элементах): %ld\n", p4 - p1);
    printf("   p1 + 2 указывает на: %d (адрес: %p)\n", *(p1 + 2), p1 + 2);
}

// ==================== 6. Поворот матрицы 90° ====================
void task6()
{
    const int N = 4;
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    printf("6. Исходная матрица:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Поворот матрицы на 90° по часовой стрелке
    // Сначала транспонируем
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Затем зеркально отображаем относительно вертикальной оси
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N - 1 - j];
            matrix[i][N - 1 - j] = temp;
        }
    }

    printf("\n   Повернутая на 90° матрица:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// ==================== 7. Седловые точки ====================
void task7()
{
    const int N = 5;
    int mat[5][5] = {
        {10, 10, 4, 10, 10},
        {10, 10, 4, 10, 10},
        {6, 6, 5, 6, 6},
        {10, 10, 4, 10, 10},
        {10, 10, 4, 10, 10}};

    printf("7. Матрица 5x5:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }

    int found = 0;
    printf("\n   Седловые точки:\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int current = mat[i][j];
            int is_min_in_row = 1;
            int is_max_in_col = 1;

            // Проверяем, минимален ли в строке
            for (int k = 0; k < N; k++)
            {
                if (mat[i][k] < current)
                {
                    is_min_in_row = 0;
                    break;
                }
            }

            // Проверяем, максимален ли в столбце
            for (int k = 0; k < N; k++)
            {
                if (mat[k][j] > current)
                {
                    is_max_in_col = 0;
                    break;
                }
            }

            if (is_min_in_row && is_max_in_col)
            {
                printf("   [%d][%d] = %d\n", i, j, current);
                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("   Седловых точек нет\n");
    }
}

// ==================== 8. Спиральное заполнение ====================
void task8()
{
    const int N = 5;
    int spiral[N][N];

    // Инициализация нулями
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            spiral[i][j] = 0;
        }
    }

    // Направления: вправо, вниз, влево, вверх
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0; // Начинаем движение вправо

    int row = 0, col = 0;
    int num = 1;

    while (num <= N * N)
    {
        spiral[row][col] = num++;

        // Пробуем сделать шаг в текущем направлении
        int next_row = row + directions[dir][0];
        int next_col = col + directions[dir][1];

        // Если вышли за границы или клетка уже заполнена - меняем направление
        if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N ||
            spiral[next_row][next_col] != 0)
        {
            dir = (dir + 1) % 4;
            next_row = row + directions[dir][0];
            next_col = col + directions[dir][1];
        }

        row = next_row;
        col = next_col;
    }

    printf("8. Матрица, заполненная по спирали (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", spiral[i][j]);
        }
        printf("\n");
    }
}

// ==================== 9. Магический квадрат ====================
void task9()
{
    const int N = 4;
    int magic[4][4] = {
        {16, 3, 2, 13},
        {5, 10, 11, 8},
        {9, 6, 7, 12},
        {4, 15, 14, 1}};

    printf("9. Проверка магического квадрата (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", magic[i][j]);
        }
        printf("\n");
    }

    // Вычисляем сумму первой строки как эталон
    int target_sum = 0;
    for (int j = 0; j < N; j++)
    {
        target_sum += magic[0][j];
    }

    int is_magic = 1;

    // Проверяем суммы строк
    for (int i = 0; i < N; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < N; j++)
        {
            row_sum += magic[i][j];
        }
        if (row_sum != target_sum)
        {
            is_magic = 0;
            break;
        }
    }

    // Проверяем суммы столбцов
    if (is_magic)
    {
        for (int j = 0; j < N; j++)
        {
            int col_sum = 0;
            for (int i = 0; i < N; i++)
            {
                col_sum += magic[i][j];
            }
            if (col_sum != target_sum)
            {
                is_magic = 0;
                break;
            }
        }
    }

    // Проверяем главную диагональ
    if (is_magic)
    {
        int diag1_sum = 0;
        for (int i = 0; i < N; i++)
        {
            diag1_sum += magic[i][i];
        }
        if (diag1_sum != target_sum)
        {
            is_magic = 0;
        }
    }

    // Проверяем побочную диагональ
    if (is_magic)
    {
        int diag2_sum = 0;
        for (int i = 0; i < N; i++)
        {
            diag2_sum += magic[i][N - 1 - i];
        }
        if (diag2_sum != target_sum)
        {
            is_magic = 0;
        }
    }

    printf("   Результат: %s\n", is_magic ? "Магический квадрат" : "Не магический квадрат");
    if (is_magic)
    {
        printf("   Магическая сумма: %d\n", target_sum);
    }
}

// ==================== 10. Удаление строки и столбца ====================
void task10()
{
    const int ROWS = 4;
    const int COLS = 5;
    int A[4][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}};

    printf("10. Исходная матрица %dx%d:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }

    // Находим строку с максимальной суммой
    int max_row_sum = 0;
    int max_row_index = 0;
    for (int i = 0; i < ROWS; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < COLS; j++)
        {
            row_sum += A[i][j];
        }
        if (row_sum > max_row_sum)
        {
            max_row_sum = row_sum;
            max_row_index = i;
        }
    }

    // Находим столбец с максимальной суммой
    int max_col_sum = 0;
    int max_col_index = 0;
    for (int j = 0; j < COLS; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            col_sum += A[i][j];
        }
        if (col_sum > max_col_sum)
        {
            max_col_sum = col_sum;
            max_col_index = j;
        }
    }

    printf("\n   Строка с максимальной суммой: %d (сумма: %d)\n", max_row_index, max_row_sum);
    printf("   Столбец с максимальной суммой: %d (сумма: %d)\n", max_col_index, max_col_sum);

    // Создаем новую матрицу 3x4
    int new_matrix[3][4];
    int new_i = 0;

    printf("\n   Новая матрица 3x4 (без строки %d и столбца %d):\n",
           max_row_index, max_col_index);

    for (int i = 0; i < ROWS; i++)
    {
        if (i == max_row_index)
            continue;

        int new_j = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (j == max_col_index)
                continue;

            new_matrix[new_i][new_j] = A[i][j];
            new_j++;
        }
        new_i++;
    }

    // Выводим новую матрицу
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%3d ", new_matrix[i][j]);
        }
        printf("\n");
    }
}

// ==================== Главное меню ====================
int main()
{
    printf("РЕШЕНИЕ 10 ЗАДАЧ ДЗ №7\n");
    printf("=======================================\n\n");

    task1();
    printf("\n");

    task2();
    printf("\n");

    task3();
    printf("\n");

    task4();
    printf("\n");

    task5();
    printf("\n");

    task6();
    printf("\n");

    task7();
    printf("\n");

    task8();
    printf("\n");

    task9();
    printf("\n");

    task10();

    return 0;
}