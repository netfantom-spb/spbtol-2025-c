#include <stdio.h>
#include <math.h>

int main()
{
    double x;

    printf("Введите значение x (в радианах): ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Ошибка ввода\n");
        return 1;
    }

    // Вычисление функции f(x) = sin(x) + cos(2x) + tan(x/3)
    double result = sin(x) + cos(2 * x) + tan(x / 3.0);

    printf("\nРезультат вычисления функции:\n");
    printf("f(%.4f) = %.6f\n", x, result);

    return 0;
}