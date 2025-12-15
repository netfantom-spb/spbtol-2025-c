#include <stdio.h>
#include <math.h>

// Структура для комплексного числа
struct Complex
{
    double real; // Действительная часть
    double imag; // Мнимая часть
};

// Функция сложения двух комплексных чисел
struct Complex add(struct Complex a, struct Complex b)
{
    struct Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Функция вычитания двух комплексных чисел
struct Complex subtract(struct Complex a, struct Complex b)
{
    struct Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// Функция умножения двух комплексных чисел
struct Complex multiply(struct Complex a, struct Complex b)
{
    struct Complex result;
    // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Функция вычисления модуля комплексного числа
double modulus(struct Complex z)
{
    // |z| = √(real² + imag²)
    return sqrt(z.real * z.real + z.imag * z.imag);
}

// Функция вывода комплексного числа
void printComplex(struct Complex z)
{
    if (z.imag >= 0)
    {
        printf("%.2f + %.2fi", z.real, z.imag);
    }
    else
    {
        printf("%.2f - %.2fi", z.real, -z.imag);
    }
}

int main()
{
    struct Complex z1, z2;

    // Ввод первого комплексного числа
    printf("Введите первое комплексное число (действительная и мнимая части):\n");
    printf("z1.real = ");
    scanf("%lf", &z1.real);
    printf("z1.imag = ");
    scanf("%lf", &z1.imag);

    // Ввод второго комплексного числа
    printf("\nВведите второе комплексное число (действительная и мнимая части):\n");
    printf("z2.real = ");
    scanf("%lf", &z2.real);
    printf("z2.imag = ");
    scanf("%lf", &z2.imag);

    // Вычисление операций
    struct Complex sum = add(z1, z2);
    struct Complex diff = subtract(z1, z2);
    struct Complex prod = multiply(z1, z2);
    double mod1 = modulus(z1);
    double mod2 = modulus(z2);

    // Вывод результатов
    printf("\n==========================================\n");
    printf("Результаты операций с комплексными числами\n");
    printf("==========================================\n\n");

    printf("Первое число: ");
    printComplex(z1);
    printf(" (|z1| = %.2f)\n", mod1);

    printf("Второе число: ");
    printComplex(z2);
    printf(" (|z2| = %.2f)\n\n", mod2);

    printf("Сложение: ");
    printComplex(z1);
    printf(" + ");
    printComplex(z2);
    printf(" = ");
    printComplex(sum);
    printf("\n");

    printf("Вычитание: ");
    printComplex(z1);
    printf(" - ");
    printComplex(z2);
    printf(" = ");
    printComplex(diff);
    printf("\n");

    printf("Умножение: ");
    printComplex(z1);
    printf(" * ");
    printComplex(z2);
    printf(" = ");
    printComplex(prod);
    printf("\n");

    printf("Модуль первого числа: |z1| = %.2f\n", mod1);
    printf("Модуль второго числа: |z2| = %.2f\n", mod2);

    printf("\n==========================================\n");

    return 0;
}