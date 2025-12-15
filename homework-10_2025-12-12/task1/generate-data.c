#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *file;
    int i;

    file = fopen("data.txt", "w");
    if (file == NULL)
    {
        printf("Ошибка: не удалось открыть файл data.txt для записи!\n");
        return 1;
    }

    srand(time(NULL));

    // Генерируем и записываем 100 случайных чисел
    for (i = 0; i < 100; i++)
    {
        double num = (rand() % 2000000 - 1000000) / 1000.0;
        fprintf(file, "%.6f\n", num); // Записываем с 6 знаками после точки
    }

    fclose(file);
    return 0;
}