#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{
    FILE *input_file = fopen("series.txt", "r");
    if (!input_file)
    {
        printf("Ошибка открытия файла series.txt\n");
        return 1;
    }

    // Чтение данных для определения количества элементов
    double value;
    int n = 0;

    // Первый проход: подсчет количества элементов и нахождение min/max
    rewind(input_file);
    double min_val = DBL_MAX;
    double max_val = -DBL_MAX;

    while (fscanf(input_file, "%lf", &value) == 1)
    {
        n++;
        if (value < min_val)
            min_val = value;
        if (value > max_val)
            max_val = value;
    }

    if (n == 0)
    {
        printf("Файл пуст\n");
        fclose(input_file);
        return 1;
    }

    if (min_val == max_val)
    {
        printf("Все значения одинаковы, нормализация невозможна\n");
        fclose(input_file);
        return 1;
    }

    // Выделение памяти для хранения данных
    double *original = (double *)malloc(n * sizeof(double));
    double *normalized = (double *)malloc(n * sizeof(double));
    double *smoothed = (double *)malloc(n * sizeof(double));

    if (!original || !normalized || !smoothed)
    {
        printf("Ошибка выделения памяти\n");
        free(original);
        free(normalized);
        free(smoothed);
        fclose(input_file);
        return 1;
    }

    // Второй проход: чтение значений в массив
    rewind(input_file);
    for (int i = 0; i < n; i++)
    {
        fscanf(input_file, "%lf", &original[i]);
    }
    fclose(input_file);

    // 1. Нормализация данных
    for (int i = 0; i < n; i++)
    {
        normalized[i] = (original[i] - min_val) / (max_val - min_val);
    }

    // 2. Экспоненциальное сглаживание
    double alpha;

    printf("Введите параметр сглаживания alpha (0 < alpha < 1): ");
    if (scanf("%lf", &alpha) != 1 || alpha <= 0 || alpha >= 1)
    {
        printf("Некорректное значение alpha. Должно быть: 0 < alpha < 1\n");
        free(original);
        free(normalized);
        free(smoothed);
        return 1;
    }

    // Первое сглаженное значение
    smoothed[0] = normalized[0];

    // Остальные значения
    for (int i = 1; i < n; i++)
    {
        smoothed[i] = alpha * normalized[i] + (1 - alpha) * smoothed[i - 1];
    }

    // 3. Запись только сглаженных значений в файл out.txt
    FILE *output_file = fopen("out.txt", "w");
    if (!output_file)
    {
        printf("Ошибка создания файла out.txt\n");
        free(original);
        free(normalized);
        free(smoothed);
        return 1;
    }

    // Записываем только сглаженные значения (по одному на строку)
    for (int i = 0; i < n; i++)
    {
        fprintf(output_file, "%.6f\n", smoothed[i]);
    }

    fclose(output_file);

    // Уведомление о завершении
    printf("Данные выведены в файл out.txt\n");

    // Освобождение памяти
    free(original);
    free(normalized);
    free(smoothed);

    return 0;
}