#include <stdio.h>
#include <math.h>

int main()
{
    double x, sum = 0;
    int n = 5; // Количество членов ряда (от x^0 до x^4)

    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Вычисление суммы с использованием цикла
    for (int i = 0; i < n; i++)
    {
        sum += pow(x, i); // x^0 = 1
    }

    printf("S = %.6f\n", sum);

    return 0;
}