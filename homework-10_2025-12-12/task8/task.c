#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Максимальная длина строки

int main()
{
    FILE *file = fopen("data.txt", "r");
    if (!file)
    {
        printf("Ошибка открытия файла data.txt\n");
        return 1;
    }

    char longest_line[MAX_LINE_LENGTH] = ""; // Самая длинная строка
    char current_line[MAX_LINE_LENGTH];      // Текущая строка
    int max_length = 0;                      // Длина самой длинной строки

    printf("Поиск самой длинной строки в файле...\n\n");

    // Читаем файл построчно
    while (fgets(current_line, MAX_LINE_LENGTH, file) != NULL)
    {
        // Убираем символ новой строки в конце, если есть
        size_t length = strlen(current_line);
        if (length > 0 && current_line[length - 1] == '\n')
        {
            current_line[length - 1] = '\0';
            length--;
        }

        // Сравниваем с текущей самой длинной строкой
        if (length > max_length)
        {
            max_length = length;
            strcpy(longest_line, current_line);
        }
    }

    fclose(file);

    // Выводим результат
    if (max_length > 0)
    {
        printf("Самая длинная строка (%d символов):\n", max_length);
        printf("=====================================\n");
        printf("%s\n", longest_line);
        printf("=====================================\n");
    }
    else
    {
        printf("Файл пуст\n");
    }

    return 0;
}