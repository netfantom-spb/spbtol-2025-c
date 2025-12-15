#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// ==================== Вспомогательные функции ====================

// Для задачи 2: Форматирование телефонного номера
char *format_phone_number(const char *digits)
{
    static char formatted[20];
    if (strlen(digits) != 10)
        return "Ошибка: нужно 10 цифр";

    for (int i = 0; i < 10; i++)
    {
        if (!isdigit(digits[i]))
            return "Ошибка: только цифры";
    }

    sprintf(formatted, "(%c%c%c) %c%c%c-%c%c%c%c",
            digits[0], digits[1], digits[2],
            digits[3], digits[4], digits[5],
            digits[6], digits[7], digits[8], digits[9]);
    return formatted;
}

// Для задачи 5: Разделение строки
void split_string(const char *str, char delimiter)
{
    char copy[1000];
    strcpy(copy, str);

    char *token = strtok(copy, &delimiter);
    int count = 0;

    while (token != NULL)
    {
        printf("%d: %s\n", ++count, token);
        token = strtok(NULL, &delimiter);
    }

    if (count == 0)
    {
        printf("Разделитель не найден\n");
    }
}

// Для задачи 6: Проверка целого числа
int is_integer(const char *str)
{
    // Если строка пустая - невалидно
    if (str[0] == '\0')
    {
        return 0;
    }

    int i = 0;

    // Пропускаем начальные пробелы НЕЛЬЗЯ - если есть пробелы, то невалидно
    if (isspace(str[0]))
    {
        return 0;
    }

    // Проверка знака в начале
    if (str[0] == '+' || str[0] == '-')
    {
        i = 1;
        // Если после знака сразу конец строки - невалидно
        if (str[i] == '\0')
        {
            return 0;
        }
    }

    // Проверка всех символов на цифры
    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }

    return 1;
}

// Для задачи 8: Нормализация пробелов
void normalize_spaces(char *str)
{
    int i = 0, j = 0;
    int in_space = 0;

    // Пропускаем начальные пробелы
    while (str[i] != '\0' && isspace(str[i]))
    {
        i++;
    }

    // Обрабатываем остальную строку
    while (str[i] != '\0')
    {
        if (isspace(str[i]))
        {
            if (!in_space)
            {
                str[j++] = ' ';
                in_space = 1;
            }
        }
        else
        {
            str[j++] = str[i];
            in_space = 0;
        }
        i++;
    }

    // Удаляем последний пробел, если есть
    if (j > 0 && str[j - 1] == ' ')
    {
        j--;
    }

    str[j] = '\0';
}

// ==================== Задачи ====================

// Задача 1: Шифр Цезаря
void task1()
{
    char text[1000];
    int shift;

    printf("Введите текст (только латинские буквы): ");
    getchar();
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Введите сдвиг: ");
    scanf("%d", &shift);

    printf("Зашифрованный текст: ");
    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift) % 26 + base;
        }
        printf("%c", c);
    }
    printf("\n\n");
}

// Задача 2: Форматирование номера
void task2()
{
    char number[100];

    printf("Введите номер (только цифры, 10 символов): ");
    scanf("%s", number);

    char *result = format_phone_number(number);
    printf("Отформатированный номер: %s\n\n", result);
}

// Задача 3: Удаление однострочных комментариев
void task3()
{
    char code[1000];

    printf("Введите строку с C-кодом:\n");
    getchar();
    fgets(code, sizeof(code), stdin);

    printf("Код без комментариев:\n");
    int in_comment = 0;

    for (int i = 0; code[i] != '\0'; i++)
    {
        if (!in_comment && code[i] == '/' && code[i + 1] == '/')
        {
            in_comment = 1;
        }

        if (!in_comment)
        {
            printf("%c", code[i]);
        }

        if (code[i] == '\n')
        {
            in_comment = 0;
        }
    }
    printf("\n");
}

// Задача 4: Подсчет символов
void task4()
{
    char str[1000];
    int counts[256] = {0};

    printf("Введите строку: ");
    getchar();
    fgets(str, sizeof(str), stdin);

    // Подсчет символов
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '\n')
        {
            counts[(unsigned char)str[i]]++;
        }
    }

    printf("\nЧастота символов:\n");
    for (int i = 0; i < 256; i++)
    {
        if (counts[i] > 0)
        {
            if (isprint(i))
            {
                printf("'%c': %d раз\n", i, counts[i]);
            }
            else
            {
                printf("'\\x%02x': %d раз\n", i, counts[i]);
            }
        }
    }
    printf("\n");
}

// Задача 5: Разделение строки
void task5()
{
    char str[1000];
    char delimiter;

    printf("Введите строку: ");
    getchar();
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Введите разделитель: ");
    scanf(" %c", &delimiter);

    printf("Результат разделения:\n");
    split_string(str, delimiter);
    printf("\n");
}

// Задача 6: Проверка целого числа
void task6()
{
    char str[100];

    printf("Введите строку для проверки: ");
    getchar(); // Очистить буфер от предыдущего ввода
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Удалить символ новой строки

    int result = is_integer(str);
    printf("Результат: %s -> %s\n\n", str, result ? "валидно" : "не валидно");
}

// Задача 7: Слова максимальной длины
void task7()
{
    char text[1000];

    printf("Введите строку: ");
    getchar(); // Очистить буфер от предыдущего ввода
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    // Находим максимальную длину слова
    int max_len = 0;
    int current_len = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != ' ')
        {
            current_len++;
        }
        else
        {
            if (current_len > max_len)
            {
                max_len = current_len;
            }
            current_len = 0;
        }
    }
    if (current_len > max_len)
    {
        max_len = current_len;
    }

    if (max_len == 0)
    {
        printf("Слова не найдены\n\n");
        return;
    }

    printf("Слова максимальной длины (%d символов):\n", max_len);

    // Выводим слова максимальной длины
    current_len = 0;
    char word[100];
    int word_idx = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != ' ')
        {
            word[word_idx++] = text[i];
            current_len++;
        }

        if (text[i] == ' ' || text[i + 1] == '\0')
        {
            word[word_idx] = '\0';
            if (current_len == max_len && word_idx > 0)
            {
                printf("- %s\n", word);
            }
            current_len = 0;
            word_idx = 0;
        }
    }
    printf("\n");
}

// Задача 8: Нормализация пробелов
void task8()
{
    char text[1000];

    printf("Введите строку: ");
    getchar(); // Очистить буфер от предыдущего ввода
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    char result[1000];
    strcpy(result, text);

    normalize_spaces(result);

    printf("Нормализованная строка: \"%s\"\n\n", result);
}

// ==================== Главное меню ====================
void print_menu()
{
    printf("\n====================================\n");
    printf("          МЕНЮ ПРОГРАММЫ           \n");
    printf("====================================\n");
    printf("1. Шифр Цезаря\n");
    printf("2. Форматирование телефонного номера\n");
    printf("3. Удаление однострочных комментариев\n");
    printf("4. Подсчет частоты символов\n");
    printf("5. Разделение строки\n");
    printf("6. Проверка целого числа\n");
    printf("7. Слова максимальной длины\n");
    printf("8. Нормализация пробелов\n");
    printf("0. Выход\n");
    printf("====================================\n");
    printf("Выберите задачу (0-8): ");
}

int main()
{
    int choice;

    do
    {
        print_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n\n");
        }
    } while (choice != 0);

    return 0;
}