#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file;
    int i;
    
    // Открываем файл для записи
    file = fopen("points.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    
    srand(time(NULL));
    
    // Генерируем 20 точек (можно изменить количество)
    double x = 0.0;
    for (i = 0; i < 20; i++) {
        // Простая функция: f(x) = x^2
        double y = x * x;
        
        // Записываем пару x y
        fprintf(file, "%.2f %.2f\n", x, y);
        
        // Увеличиваем x на случайное значение от 0.5 до 1.5
        x += 0.5 + (rand() % 100) / 100.0;
    }
    
    fclose(file);
    printf("Файл points.txt создан\n");
    
    return 0;
}