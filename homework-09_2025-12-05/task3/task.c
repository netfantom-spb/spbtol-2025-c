#include <stdio.h>
#include <math.h>

// Определяем константу π
#define PI 3.14159265358979323846

int main()
{
    double degrees, radians, sine_value;

    printf("Введите угол в градусах: ");
    if (scanf("%lf", &degrees) != 1)
    {
        printf("Ошибка ввода\n");
        return 1;
    }

    // Перевод градусов в радианы
    radians = degrees * PI / 180.0;

    // Вычисление синуса
    sine_value = sin(radians);

    // Вывод результатов
    printf("\nРезультаты:\n");
    printf("Угол: %.2f°\n", degrees);
    printf("В радианах: %.6f рад\n", radians);
    printf("sin(%.6f) = %.6f\n", radians, sine_value);

    return 0;
}