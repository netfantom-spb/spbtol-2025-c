#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;

    printf("Введите координаты точки A(x, y, z):\n");
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    printf("z = ");
    scanf("%lf", &z);

    // Вычисление расстояния до начала координат
    double distance = sqrt(x * x + y * y + z * z);
    // можно и так, но для небольших степеней простое умножение эффективнее
    // double distance = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

    printf("\nКоординаты точки: A(%.2f, %.2f, %.2f)\n", x, y, z);
    printf("Расстояние до начала координат: %.4f\n", distance);

    return 0;
}