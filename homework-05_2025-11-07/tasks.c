#include <stdio.h>
#include <math.h>

/* 1 */
void task1()
{
    int a, b, c;
    printf("Задача 1\nВведите три целых числа: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a > b && a > c)
        printf("Максимум: %d\n", a);
    else if (b > a && b > c)
        printf("Максимум: %d\n", b);
    else if (c > a && c > b)
        printf("Максимум: %d\n", c);
    else
        printf("Несколько чисел равны и максимальны\n");
}

/* 2 */
void task2()
{
    double x1, y1, x2, y2;
    printf("\nЗадача 2\nВведите x1 y1 x2 y2: ");
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

    if (x1 == x2)
    {
        printf("Прямая вертикальная, угловой коэффициент не определён.\n");
    }
    else
    {
        double k = (y2 - y1) / (x2 - x1);
        double b = y1 - k * x1;
        printf("y = %.2fx + %.2f\n", k, b);
    }
}

/* 3 */
void task3()
{
    double S, P;
    printf("\nЗадача 3\nВведите сумму покупки и оплату: ");
    scanf("%lf%lf", &S, &P);

    if (P < S)
        printf("Недостаточно денег\n");
    else
        printf("Сдача: %.2f\n", P - S);
}

/* 4 */
void task4()
{
    int a, b;
    printf("\nЗадача 4\nВведите два целых числа: ");
    scanf("%d%d", &a, &b);

    if (b == 0)
    {
        printf("Деление на ноль невозможно\n");
        return;
    }

    if (a % b == 0)
        printf("Делится без остатка\n");
    else
        printf("Не делится, остаток = %d\n", a % b);
}

/* 5 */
void task5()
{
    double a, b;
    char op;
    printf("\nЗадача 5\nВведите выражение (a + b): ");
    scanf("%lf %c %lf", &a, &op, &b);

    if (op == '/' && b == 0)
    {
        printf("Ошибка: деление на ноль.\n");
        return;
    }

    if (op == '+')
        printf("Результат: %.2f\n", a + b);
    else if (op == '-')
        printf("Результат: %.2f\n", a - b);
    else if (op == '*')
        printf("Результат: %.2f\n", a * b);
    else if (op == '/')
        printf("Результат: %.2f\n", a / b);
}

/* 6 */
void task6()
{
    int t;
    printf("\nЗадача 6\nВведите температуру: ");
    scanf("%d", &t);

    if (t < -20)
        printf("Очень холодно\n");
    else if (t < 0)
        printf("Холодно\n");
    else if (t < 10)
        printf("Прохладно\n");
    else if (t < 25)
        printf("Тепло\n");
    else
        printf("Жарко\n");
}

/* 7 */
void task7()
{
    int y;
    printf("\nЗадача 7\nВведите год: ");
    scanf("%d", &y);

    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        printf("Високосный год\n");
    else
        printf("Обычный год\n");
}

/* 8 */
void task8()
{
    double a, b, c;
    printf("\nЗадача 8\nВведите коэффициенты a b c: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    double D = b * b - 4 * a * c;
    if (D > 0)
        printf("Корни: %.2f %.2f\n", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
    else if (D == 0)
        printf("Корень: %.2f\n", -b / (2 * a));
    else
        printf("Корней нет\n");
}

/* 9 */
void task9()
{
    int x;
    printf("\nЗадача 9\nВведите количество баллов: ");
    scanf("%d", &x);

    if (x < 0 || x > 100)
        printf("Ошибка: неверное значение.\n");
    else if (x < 50)
        printf("Неудовлетворительно\n");
    else if (x < 70)
        printf("Удовлетворительно\n");
    else if (x < 85)
        printf("Хорошо\n");
    else
        printf("Отлично\n");
}

/* 10 */
void task10()
{
    double a, b, c;
    printf("\nЗадача 10\nВведите стороны треугольника: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    if (a + b <= c || a + c <= b || b + c <= a)
        printf("Треугольник не существует.\n");
    else if (a == b && b == c)
        printf("Равносторонний\n");
    else if (a == b || a == c || b == c)
        printf("Равнобедренный\n");
    else
        printf("Разносторонний\n");
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    return 0;
}
