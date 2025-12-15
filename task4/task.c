#include <stdio.h>
#include <math.h>

int main()
{
    FILE *file = fopen("data.txt", "r");
    if (!file)
    {
        printf("Ошибка открытия файла data.txt\n");
        return 1;
    }

    double x, y;
    double sum_x = 0, sum_y = 0;
    double sum_xy = 0, sum_x2 = 0, sum_y2 = 0;
    int n = 0;

    // Чтение данных из файла и вычисление сумм
    while (fscanf(file, "%lf %lf", &x, &y) == 2)
    {
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
        sum_y2 += y * y;
        n++;
    }
    fclose(file);

    if (n < 2)
    {
        printf("Недостаточно данных для вычисления корреляции (нужно минимум 2 пары)\n");
        return 1;
    }

    // Вычисление коэффициента корреляции Пирсона
    double numerator = n * sum_xy - sum_x * sum_y;
    double denominator1 = n * sum_x2 - sum_x * sum_x;
    double denominator2 = n * sum_y2 - sum_y * sum_y;

    if (denominator1 <= 0 || denominator2 <= 0)
    {
        printf("Ошибка: дисперсия одной из переменных равна нулю (все значения одинаковы)\n");
        return 1;
    }

    double r = numerator / sqrt(denominator1 * denominator2);

    // Вывод результата
    printf("Коэффициент корреляции Пирсона: r = %.6f\n", r);

    // Определение типа зависимости
    double abs_r = fabs(r);
    printf("|r| = %.6f\n", abs_r);

    printf("Тип зависимости: ");
    if (abs_r < 0.3)
    {
        printf("слабая\n");
    }
    else if (abs_r < 0.7)
    {
        printf("умеренная\n");
    }
    else
    {
        printf("сильная\n");
    }

    return 0;
}