#include <stdio.h>
#include <stdbool.h>

// Функция печати массива
void printArray(int arr[], int size, const char *message)
{
    if (message != NULL)
    {
        printf("%s", message);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ==================== 1. Подсчет количества ====================
void task1()
{
    int arr[] = {5, -2, 0, 8, -1, 3, 0, -4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("=== ЗАДАЧА 1 ===\n");
    printArray(arr, size, "Исходный массив: ");

    int positive = 0, negative = 0, zero = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
        else
            zero++;
    }

    printf("Положительных: %d\n", positive);
    printf("Отрицательных: %d\n", negative);
    printf("Нулевых: %d\n\n", zero);
}

// ==================== 2. Индекс первого отрицательного числа ====================
void task2()
{
    int arr[] = {5, -2, 0, 8, -1, 3, 0, -4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("=== ЗАДАЧА 2 ===\n");
    printArray(arr, size, "Исходный массив: ");

    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            index = i;
            break;
        }
    }

    printf("Индекс первого отрицательного числа: %d\n\n", index);
}

// ==================== 3. Заменить все отрицательные числа на 0 ====================
void task3()
{
    int arr[] = {5, -2, 0, 8, -1, 3, 0, -4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("=== ЗАДАЧА 3 ===\n");
    printArray(arr, size, "Исходный массив: ");

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            arr[i] = 0;
        }
    }

    printArray(arr, size, "Массив после замены: ");
    printf("\n");
}

// ==================== 3. Сумма элементов на четных позициях ====================
void task4()
{
    int arr[] = {5, -2, 0, 8, -1, 3, 0, -4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("=== ЗАДАЧА 4 ===\n");
    printArray(arr, size, "Исходный массив: ");

    int sum = 0;
    for (int i = 0; i < size; i += 2)
    {
        sum += arr[i];
    }

    printf("Сумма элементов на четных позициях (индексы 0,2,4...): %d\n\n", sum);
}

// ==================== 5. Подсчет локальных минимумов ====================
void task5()
{
    int arr[] = {5, -2, 0, 8, -1, 3, 0, -4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("=== ЗАДАЧА 5 ===\n");
    printArray(arr, size, "Исходный массив: ");

    int count = 0;
    printf("Локальные минимумы (индекс: значение): ");

    for (int i = 0; i < size; i++)
    {
        bool hasLeftNeighbor = (i > 0);
        bool hasRightNeighbor = (i < size - 1);

        if (hasLeftNeighbor && hasRightNeighbor)
        {
            if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
            {
                count++;
                printf("[%d: %d] ", i, arr[i]);
            }
        }
    }

    printf("\nКоличество локальных минимумов: %d\n\n", count);
}

// ==================== 6. Найти сумму элементов между ====================
void task6()
{
    int arr[] = {5, -2, 0, 8, -1, 3, 0, -4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("=== ЗАДАЧА 6 ===\n");
    printArray(arr, size, "Исходный массив: ");

    // Находим максимальный элемент
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    printf("Максимальный элемент: %d\n", maxVal);

    // Находим первый индекс максимального элемента
    int firstIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == maxVal)
        {
            firstIndex = i;
            break;
        }
    }

    // Находим последний индекс максимального элемента
    int lastIndex = -1;
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == maxVal)
        {
            lastIndex = i;
            break;
        }
    }

    printf("Первый индекс максимального: %d\n", firstIndex);
    printf("Последний индекс максимального: %d\n", lastIndex);

    // Если только одно максимальное значение или они рядом
    if (firstIndex == -1 || lastIndex == -1 || firstIndex >= lastIndex - 1)
    {
        printf("Сумма элементов между ними: 0\n\n");
        return;
    }

    // Считаем сумму между ними
    int sum = 0;
    for (int i = firstIndex + 1; i < lastIndex; i++)
    {
        sum += arr[i];
    }

    printf("Сумма элементов между ними: %d\n\n", sum);
}

// ==================== 7. Подсчет уникальных значений ====================
void task7()
{
    int arr[] = {5, -2, 0, 8, -1, 3, 0, -4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("=== ЗАДАЧА 7 ===\n");
    printArray(arr, size, "Исходный массив: ");

    int uniqueCount = 0;

    for (int i = 0; i < size; i++)
    {
        bool isUnique = true;

        // Проверяем, есть ли такой же элемент в остальной части массива
        for (int j = 0; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
        {
            uniqueCount++;
        }
    }

    printf("Количество уникальных значений: %d\n\n", uniqueCount);
}

// ==================== 8. Перевернуть массив ====================
void task8()
{
    int arr[] = {5, -2, 0, 8, -1, 3, 0, -4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("=== ЗАДАЧА 8 ===\n");
    printArray(arr, size, "Исходный массив: ");

    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

    printArray(arr, size, "Перевернутый массив: ");
    printf("\n");
}

int main()
{
    printf("=== ВЫПОЛНЕНИЕ 8 ЗАДАЧ ДЗ№6 ===\n\n");

    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();

    return 0;
}