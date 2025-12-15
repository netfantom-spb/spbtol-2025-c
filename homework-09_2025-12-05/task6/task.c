#include <stdio.h>
#include <math.h>

// Определение структуры Point
struct Point
{
    double x;
    double y;
};

// Функция для вычисления расстояния между двумя точками
double caclDistance(struct Point p1, struct Point p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    struct Point pointA, pointB;

    printf("Введите координаты точки A:\n");
    printf("x1 = ");
    scanf("%lf", &pointA.x);
    printf("y1 = ");
    scanf("%lf", &pointA.y);

    printf("\nВведите координаты точки B:\n");
    printf("x2 = ");
    scanf("%lf", &pointB.x);
    printf("y2 = ");
    scanf("%lf", &pointB.y);

    // Вычисление расстояния через функцию
    double distance = caclDistance(pointA, pointB);

    // Вывод результатов

    printf("Расстояние между точками: %.4f\n", distance);
    printf("─────────────────────────────────────\n");

    return 0;
}