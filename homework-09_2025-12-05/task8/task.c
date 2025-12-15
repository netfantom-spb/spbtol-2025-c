#include <stdio.h>
#include <string.h>

struct Product
{
    char name[100];
    double price;
    int quantity;
};

void inputProduct(struct Product *product)
{
    printf("Название товара: ");
    while (getchar() != '\n')
        ;
    fgets(product->name, sizeof(product->name), stdin);
    product->name[strcspn(product->name, "\n")] = '\0';

    printf("Цена за единицу: ");
    scanf("%lf", &product->price);

    printf("Количество: ");
    scanf("%d", &product->quantity);

    printf("\n");
}

double calculateProductCost(const struct Product *product)
{
    return product->price * product->quantity;
}

double calculateTotalCost(struct Product products[], int n)
{
    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        total += calculateProductCost(&products[i]);
    }
    return total;
}

int main()
{
    int n;

    printf("Введите количество товаров: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Ошибка: неверное количество товаров\n");
        return 1;
    }

    struct Product products[n];

    printf("\nВведите информацию о товарах:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nТовар %d:\n", i + 1);
        inputProduct(&products[i]);
    }

    printf("\n=== ЧЕК ===\n");
    printf("-------------------------------------------\n");
    printf("№  Название           Цена    Кол-во  Сумма\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        double cost = calculateProductCost(&products[i]);
        printf("%d  %-15s %7.2f %6d %9.2f\n",
               i + 1,
               products[i].name,
               products[i].price,
               products[i].quantity,
               cost);
    }

    printf("-------------------------------------------\n");
    double total = calculateTotalCost(products, n);
    printf("Итого к оплате: %.2f\n", total);
    printf("-------------------------------------------\n");

    return 0;
}