#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("data.txt", "r");
    if (!file)
    {
        printf("Ошибка открытия файла matrix.txt\n");
        return 1;
    }

    // Читаем первую строку для определения размера
    char line[1000];
    if (!fgets(line, sizeof(line), file))
    {
        printf("Файл пуст\n");
        fclose(file);
        return 1;
    }

    // Определяем количество чисел в первой строке
    int n = 0;
    char *token = strtok(line, " \t\n");
    while (token != NULL)
    {
        n++;
        token = strtok(NULL, " \t\n");
    }

    if (n == 0)
    {
        printf("Первая строка не содержит чисел\n");
        fclose(file);
        return 1;
    }

    // Возвращаемся к началу файла
    rewind(file);

    // Выделяем память для матрицы
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (!matrix)
    {
        printf("Ошибка выделения памяти\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (!matrix[i])
        {
            printf("Ошибка выделения памяти\n");
            for (int j = 0; j < i; j++)
            {
                free(matrix[j]);
            }
            free(matrix);
            fclose(file);
            return 1;
        }
    }

    // Чтение матрицы из файла
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(file, "%d", &matrix[i][j]) != 1)
            {
                printf("Ошибка чтения элемента [%d][%d]\n", i, j);
                for (int k = 0; k < n; k++)
                {
                    free(matrix[k]);
                }
                free(matrix);
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);

    // Вычисление суммы элементов под главной диагональю
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            { // Элементы под главной диагональю
                sum += matrix[i][j];
            }
        }
    }

    // Вывод матрицы
    printf("Матрица %dx%d:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nСумма элементов под главной диагональю: %d\n", sum);

    // Освобождение памяти
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}