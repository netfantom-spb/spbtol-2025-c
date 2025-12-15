#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *input_file = fopen("data.txt", "r");
    if (!input_file)
    {
        printf("Ошибка открытия файла input.txt\n");
        return 1;
    }

    FILE *output_file = fopen("out.txt", "w");
    if (!output_file)
    {
        printf("Ошибка создания файла out.txt\n");
        fclose(input_file);
        return 1;
    }

    char ch;

    printf("Обработка файла...\n");

    // Читаем посимвольно и преобразуем строчные буквы в заглавные
    while ((ch = fgetc(input_file)) != EOF)
    {
        if (islower(ch))
        {                                    // Если символ - строчная буква
            fputc(toupper(ch), output_file); // Преобразуем в заглавную
        }
        else
        {
            fputc(ch, output_file); // Иначе записываем как есть
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Текст успешно преобразован и записан в out.txt\n");

    return 0;
}