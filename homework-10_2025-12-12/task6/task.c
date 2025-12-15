#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input_file = fopen("data.txt", "r");
    if (!input_file)
    {
        printf("Ошибка открытия файла data.txt\n");
        return 1;
    }

    // Открываем файл для записи четных чисел
    FILE *output_file = fopen("out.txt", "w");
    if (!output_file)
    {
        printf("Ошибка создания файла out.txt\n");
        fclose(input_file);
        return 1;
    }

    int number;
    int count = 0;

    printf("Чтение чисел из файла data.txt...\n");

    // Читаем числа из файла и записываем четные в новый файл
    while (fscanf(input_file, "%d", &number) == 1)
    {
        if (number % 2 == 0)
        { // Проверяем, четное ли число
            fprintf(output_file, "%d\n", number);
            count++;
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Найдено %d четных чисел\n", count);
    printf("Четные числа записаны в файл out.txt\n");

    return 0;
}