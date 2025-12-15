#include <stdio.h>
#include <string.h>

// Определение структуры Student
struct Student
{
    char name[50];
    char group[20];
    int grade;
};

int main()
{
    int n;

    // Ввод количества студентов
    printf("Введите количество студентов: ");
    scanf("%d", &n);

    // Проверка корректности ввода
    if (n <= 0)
    {
        printf("Количество студентов должно быть положительным\n");
        return 1;
    }

    // Создание массива студентов
    struct Student students[n];

    // Ввод данных о студентах
    printf("\nВведите данные о студентах:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nСтудент %d:\n", i + 1);

        // Очистка буфера ввода перед чтением строк
        while (getchar() != '\n')
            ;

        printf("Имя: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        // Удаляем символ новой строки в конце
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Группа: ");
        fgets(students[i].group, sizeof(students[i].group), stdin);
        students[i].group[strcspn(students[i].group, "\n")] = '\0';

        printf("Оценка (0-100): ");
        scanf("%d", &students[i].grade);

        // Проверка корректности оценки
        if (students[i].grade < 0 || students[i].grade > 100)
        {
            printf("Ошибка: оценка должна быть от 0 до 100\n");
            return 1;
        }
    }

    // Поиск студента с максимальной оценкой
    int max_index = 0; // Индекс студента с максимальной оценкой
    int max_grade = students[0].grade;

    for (int i = 1; i < n; i++)
    {
        if (students[i].grade > max_grade)
        {
            max_grade = students[i].grade;
            max_index = i;
        }
    }

    // Вывод результатов
    printf("\n═══════════════════════════════════════════════════\n");
    printf("Список всех студентов:\n");
    printf("═══════════════════════════════════════════════════\n");
    printf("%-4s %-30s %-15s %-6s\n", "№", "Имя", "Группа", "Оценка");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%-4d %-30s %-15s %-6d",
               i + 1, students[i].name, students[i].group, students[i].grade);

        // Выделяем лучшего студента
        if (i == max_index)
        {
            printf(" ← ЛУЧШИЙ");
        }
        printf("\n");
    }

    printf("\n═══════════════════════════════════════════════════\n");
    printf("Студент с максимальной оценкой:\n");
    printf("═══════════════════════════════════════════════════\n");
    printf("Имя:    %s\n", students[max_index].name);
    printf("Группа: %s\n", students[max_index].group);
    printf("Оценка: %d\n", students[max_index].grade);
    printf("═══════════════════════════════════════════════════\n");

    return 0;
}