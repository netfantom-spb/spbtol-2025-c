#include <stdio.h>
#include <limits.h>

int main()
{
    FILE *file = fopen("data.txt", "r");
    if (!file)
    {
        printf("Ошибка открытия файла data.txt\n");
        return 1;
    }

    int number;
    int min = INT_MAX; // Начальное значение - максимальное целое
    int max = INT_MIN; // Начальное значение - минимальное целое
    int count = 0;

    printf("Чтение целых чисел из файла data.txt...\n");

    // Читаем все числа из файла
    while (fscanf(file, "%d", &number) == 1)
    {
        count++;

        // Обновляем минимум
        if (number < min)
        {
            min = number;
        }

        // Обновляем максимум
        if (number > max)
        {
            max = number;
        }
    }

    fclose(file);

    if (count == 0)
    {
        printf("Файл пуст или не содержит целых чисел\n");
    }
    else
    {
        printf("Минимальное значение: %d\n", min);
        printf("Максимальное значение: %d\n", max);
    }

    return 0;
}