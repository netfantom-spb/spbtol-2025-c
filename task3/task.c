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
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    int n = 0;

    // Чтение данных из файла и вычисление сумм
    while (fscanf(file, "%lf %lf", &x, &y) == 2)
    {
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
        n++;
    }
    fclose(file);

    if (n < 2)
    {
        printf("Недостаточно данных для аппроксимации (нужно минимум 2 точки)\n");
        return 1;
    }

    // Вычисление коэффициентов a и b
    double denominator = n * sum_x2 - sum_x * sum_x;
    if (fabs(denominator) < 1e-10)
    {
        printf("Ошибка: знаменатель близок к нулю (вероятно, все x одинаковы)\n");
        return 1;
    }

    double a = (n * sum_xy - sum_x * sum_y) / denominator;
    double b = (sum_y - a * sum_x) / n;

    // Вывод коэффициентов
    printf("Коэффициенты линейной аппроксимации:\n");
    printf("a = %.6f\n", a);
    printf("b = %.6f\n", b);
    printf("Уравнение: y = %.6f * x + %.6f\n", a, b);

    // Переоткрываем файл для вычисления ошибки
    file = fopen("data.txt", "r");
    double error_sum = 0;

    while (fscanf(file, "%lf %lf", &x, &y) == 2)
    {
        double y_pred = a * x + b;
        double diff = y - y_pred;
        error_sum += diff * diff;
    }
    fclose(file);

    // Вычисление средней квадратичной ошибки
    double mse = error_sum / n; // Средняя квадратичная ошибка
    double rmse = sqrt(mse);    // Средняя квадратичная ошибка аппроксимации

    printf("\nСредняя квадратичная ошибка аппроксимации: %.6f\n", rmse);
    printf("Среднеквадратичное отклонение (MSE): %.6f\n", mse);

    return 0;
}