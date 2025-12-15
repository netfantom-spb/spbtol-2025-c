#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

// Функция проверки високосного года
int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция определения количества дней в месяце
int daysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return -1; // Некорректный месяц
    }
}

// Функция проверки корректности даты
int isValidDate(struct Date d)
{
    if (d.year < 1)
        return 0;
    if (d.month < 1 || d.month > 12)
        return 0;
    if (d.day < 1 || d.day > daysInMonth(d.month, d.year))
        return 0;
    return 1;
}

// Функция для получения следующей даты
struct Date getNextDay(struct Date d)
{
    struct Date next = d;

    // Проверяем, не последний ли день месяца
    if (d.day < daysInMonth(d.month, d.year))
    {
        next.day++;
    }
    else
    {
        // Последний день месяца
        next.day = 1;
        if (d.month == 12)
        {
            // Последний день года
            next.month = 1;
            next.year++;
        }
        else
        {
            next.month++;
        }
    }

    return next;
}

int main()
{
    struct Date date;

    // Ввод даты
    printf("Введите дату (день месяц год): ");
    scanf("%d %d %d", &date.day, &date.month, &date.year);

    // Проверка корректности даты
    if (!isValidDate(date))
    {
        printf("Ошибка: некорректная дата\n");
        return 1;
    }

    // Получение следующего дня
    struct Date next = getNextDay(date);

    // Вывод результата
    printf("\nВведенная дата: %02d.%02d.%d\n", date.day, date.month, date.year);
    printf("Следующий день: %02d.%02d.%d\n", next.day, next.month, next.year);

    return 0;
}