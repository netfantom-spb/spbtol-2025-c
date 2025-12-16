from book import Book
import datetime

def task1():
    """Демонстрация работы класса Book с валидацией года издания"""
    print("=" * 50)
    print("ЗАДАЧА 1: Класс 'Книга' с валидацией года издания")
    print("=" * 50)
    
    # 1. Создание книг с корректными данными
    print("\n1. Создание книг:")
    books = [
        Book("Война и мир", "Лев Толстой", 1869),
        Book("1984", "Джордж Оруэлл", 1949),
        Book("Мастер и Маргарита", "Михаил Булгаков", 1967)
    ]
    
    for i, book in enumerate(books, 1):
        print(f"  Книга {i}: {book}")
    
    # 2. Демонстрация метода display_info()
    print("\n2. Метод display_info():")
    books[0].display_info()
    
    # 3. Демонстрация геттеров
    print("\n3. Использование геттеров:")
    print(f"  Название: {books[1].title}")
    print(f"  Автор: {books[1].author}")
    print(f"  Год: {books[1].year}")
    
    # 4. Демонстрация изменения года
    print("\n4. Изменение года издания:")
    try:
        print(f"  До: {books[2]}")
        books[2].year = 1970
        print(f"  После: {books[2]}")
    except ValueError as e:
        print(f"  Ошибка: {e}")
    
    # 5. Демонстрация валидации
    print("\n5. Тест валидации года:")
    current_year = datetime.datetime.now().year
    
    # Попытка создать книгу с некорректным годом
    test_cases = [
        ("Книга из будущего", "Автор", current_year + 1),
        ("Книга с годом 0", "Автор", 0),
        ("Древняя книга", "Автор", -100)
    ]
    
    for title, author, year in test_cases:
        try:
            Book(title, author, year)
            print(f"  ✓ '{title}' создана с годом {year}")
        except ValueError as e:
            print(f"  ✗ Ошибка при создании '{title}' с годом {year}: {e}")
    
    # 6. Проверка атрибутов только для чтения
    print("\n6. Проверка атрибутов только для чтения:")
    try:
        books[0].title = "Новое название"
    except AttributeError:
        print("  ✓ title защищен от записи")
    
    try:
        books[0].author = "Новый автор"
    except AttributeError:
        print("  ✓ author защищен от записи")
    
    print("\n" + "=" * 50)
    print("Задача 1 завершена")
    print("=" * 50)


if __name__ == "__main__":
    task1()