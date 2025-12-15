#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("points.txt", "r");
    if (!file)
    {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    double x_prev, y_prev, x_curr, y_curr;
    double integral = 0.0;

    // Читаем первую точку
    if (fscanf(file, "%lf %lf", &x_prev, &y_prev) != 2)
    {
        printf("Ошибка чтения файла\n");
        fclose(file);
        return 1;
    }

    // Читаем остальные точки и вычисляем интеграл
    while (fscanf(file, "%lf %lf", &x_curr, &y_curr) == 2)
    {
        // Площадь трапеции для текущего отрезка
        double width = x_curr - x_prev;
        double avg_height = (y_prev + y_curr) / 2.0;
        integral += avg_height * width;

        // Текущая точка становится предыдущей для следующей итерации
        x_prev = x_curr;
        y_prev = y_curr;
    }

    fclose(file);

    printf("Приближенное значение интеграла: %.6f\n", integral);

    return 0;
}