#include <stdio.h>
#include <math.h>

int main()
{
    FILE *file = fopen("data.txt", "r");
    if (!file)
    {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    // Массив для хранения значений
    double values[1000]; // Предполагаем не более 1000 чисел
    double sum = 0;
    int count = 0;

    // Чтение чисел в массив
    while (fscanf(file, "%lf", &values[count]) == 1 && count < 1000)
    {
        sum += values[count];
        count++;
    }

    fclose(file);

    if (count == 0)
    {
        printf("Файл пуст\n");
        return 1;
    }

    // Вычисление среднего
    double mean = sum / count;

    // Вычисление суммы квадратов отклонений от среднего
    double sum_squared_diff = 0;
    for (int i = 0; i < count; i++)
    {
        double diff = values[i] - mean;
        sum_squared_diff += diff * diff;
    }

    // Стандартное отклонение для генеральной совокупности
    double variance = sum_squared_diff / count;
    double std_dev = sqrt(variance);

    printf("Среднее арифметическое: %.6f\n", mean);
    printf("Среднеквадратичное отклонение: %.6f\n", std_dev);

    return 0;
}