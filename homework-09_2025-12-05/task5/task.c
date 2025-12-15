#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2;
    double t1, t2;

    printf("Расчет средней скорости объекта\n\n");

    // Ввод координат и времени
    printf("Введите координаты и время для точки A:\n");
    printf("x1 = ");
    scanf("%lf", &x1);
    printf("y1 = ");
    scanf("%lf", &y1);
    printf("t1 = ");
    scanf("%lf", &t1);

    printf("\nВведите координаты и время для точки B:\n");
    printf("x2 = ");
    scanf("%lf", &x2);
    printf("y2 = ");
    scanf("%lf", &y2);
    printf("t2 = ");
    scanf("%lf", &t2);

    // Проверка корректности времени
    if (t2 <= t1)
    {
        printf("Ошибка: t2 должно быть больше t1 - прыжки назад во времени запрещены ОТО!\n");
        return 1;
    }

    // Вычисление пройденного расстояния
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Вычисление промежутка времени
    double time_interval = t2 - t1;

    // Вычисление скорости
    double velocity = distance / time_interval;

    // Вывод результатов
    printf("Средняя скорость: v = %.4f\n", velocity);

    return 0;
}