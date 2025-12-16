import datetime
from book import Book
from account import BankAccount
from car import Car
from student import Student
from shape import Shape
from rectangle import Rectangle


def task1():
    print("=" * 50)
    print("ЗАДАЧА 1: Класс 'Book'")
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

def task2():
    print("=" * 50)
    print("ЗАДАЧА 2: Класс 'BankAccount'")
    print("=" * 50)
    
    # 1. Создание счёта
    print("\n1. Создание счётов:")
    try:
        account1 = BankAccount(1000.0)
        account2 = BankAccount(500.0)
        # account3 = BankAccount(-100)  # Раскомментировать для проверки ошибки
    except ValueError as e:
        print(f"  Ошибка при создании счёта: {e}")
    
    # 2. Проверка баланса через геттер
    print("\n2. Проверка баланса:")
    print(f"  Баланс счёта 1: {account1.balance:.2f} руб.")
    print(f"  Баланс счёта 2: {account2.balance:.2f} руб.")
    
    # 3. Пополнение счёта
    print("\n3. Пополнение счёта:")
    try:
        account1.deposit(500.0)
        account2.deposit(200.0)
        # account1.deposit(-100)  # Раскомментировать для проверки ошибки
    except ValueError as e:
        print(f"  Ошибка при пополнении: {e}")
    
    # 4. Снятие средств
    print("\n4. Снятие средств:")
    try:
        # Успешное снятие
        account1.withdraw(300.0)
        
        # Попытка снять больше, чем есть
        account2.withdraw(800.0)  # Должно вернуть False
        
        # Снятие оставшихся средств
        account2.withdraw(account2.balance)
        
        # account1.withdraw(-50)  # Раскомментировать для проверки ошибки
    except ValueError as e:
        print(f"  Ошибка при снятии: {e}")
    
    # 5. Проверка финальных балансов
    print("\n5. Финальные балансы:")
    print(f"  Счёт 1: {account1.balance:.2f} руб.")
    print(f"  Счёт 2: {account2.balance:.2f} руб.")
    
    # 6. Демонстрация работы деструктора
    print("\n6. Закрытие счетов (работа деструктора):")
    del account1
    del account2
    
    print("\n" + "=" * 50)
    print("Задача 2 завершена")
    print("=" * 50)

def task3():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 3: Класс 'Car'")
    print("=" * 50)
    
    # 1. Создание одного автомобиля
    print("\n1. Создание автомобиля:")
    car = Car("Toyota", "Camry", 200.0)
    print(f"  Начальное состояние: {car}")
    
    # 2. Использование геттеров
    print("\n2. Использование геттеров:")
    print(f"  Марка: {car.brand}")
    print(f"  Модель: {car.model}")
    print(f"  Макс. скорость: {car.max_speed} км/ч")
    print(f"  Текущая скорость: {car.speed} км/ч")
    
    # 3. Тест ускорения
    print("\n3. Тест ускорения (метод accelerate):")
    car.accelerate(80)
    car.accelerate(70)
    car.accelerate(100)  # Попытка превысить максимум
    print(f"  Результат: {car}")
    
    # 4. Тест установки скорости
    print("\n4. Тест сеттера скорости:")
    try:
        car.speed = 150.0
        print(f"  ✓ Установлена скорость: {car.speed} км/ч")
    except ValueError as e:
        print(f"  ✗ Ошибка: {e}")
    
    # 5. Тест превышения скорости
    print("\n5. Тест превышения максимума:")
    try:
        car.speed = 250.0  # Максимум 200
    except ValueError as e:
        print(f"  ✗ {e}")
    
    # 6. Тест торможения
    print("\n6. Тест торможения (метод brake):")
    car.brake()
    print(f"  После торможения: {car}")
    
    print("\n" + "=" * 50)
    print("Задача 3 завершена")
    print("=" * 50)

def task4():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 4: Класс 'Student'")
    print("=" * 50)
    
    # 1. Создание студента
    print("\n1. Создание студента:")
    student = Student("Иван Петров")
    
    # 2. Использование геттера
    print("\n2. Использование геттера:")
    print(f"  Имя студента: {student.name}")
    
    # 3. Добавление оценок
    print("\n3. Добавление оценок:")
    try:
        student.add_grade(4)
        student.add_grade(5)
        student.add_grade(3)
        student.add_grade(5)
        
        # Попытка добавить некорректную оценку
        student.add_grade(6)
    except ValueError as e:
        print(f"  ✗ Ошибка: {e}")
    
    # 4. Проверка среднего балла
    print("\n4. Проверка среднего балла:")
    print(f"  Оценки: {student.grades}")
    print(f"  Средний балл: {student.average_grade:.2f}")
    
    # 5. Использование __str__
    print("\n5. Строковое представление:")
    print(f"  {student}")
    
    print("\n" + "=" * 50)
    print("Задача 4 завершена")
    print("=" * 50)
    
def task5():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 5: Классы Shape и Rectangle")
    print("=" * 50)
    
    # 1. Создание прямоугольника
    print("\n1. Создание прямоугольника:")
    try:
        rect = Rectangle("синий", 5.0, 3.0)
        print(f"  Создан: {rect}")
    except ValueError as e:
        print(f"  ✗ Ошибка: {e}")
    
    # 2. Использование методов Shape
    print("\n2. Методы базового класса Shape:")
    print(f"  Цвет: {rect.color}")
    print(f"  Площадь: {rect.area():.2f}")
    print(f"  info(): {rect.info()}")
    
    # 3. Изменение цвета через сеттер
    print("\n3. Изменение цвета (сеттер):")
    try:
        rect.color = "красный"
        print(f"  Новый цвет: {rect.color}")
        print(f"  Обновленная информация: {rect.info()}")
        
        # Попытка установить пустой цвет
        rect.color = ""
    except ValueError as e:
        print(f"  ✗ Ошибка при пустом цвете: {e}")
    
    # 4. Тест создания с некорректными параметрами
    print("\n4. Тест валидации параметров:")
    try:
        Rectangle("", 5, 3)  # Пустой цвет
    except ValueError as e:
        print(f"  ✗ Пустой цвет: {e}")
    
    try:
        Rectangle("зеленый", -5, 3)  # Отрицательная ширина
    except ValueError as e:
        print(f"  ✗ Отрицательная ширина: {e}")
    
    try:
        Rectangle("зеленый", 5, 0)  # Нулевая высота
    except ValueError as e:
        print(f"  ✗ Нулевая высота: {e}")
    
    # 5. Демонстрация абстрактности Shape
    print("\n5. Тест абстрактного класса Shape:")
    try:
        # Попытка создать экземпляр абстрактного класса
        shape = Shape("черный")
        print("  ✓ Shape создан")
    except (TypeError, NotImplementedError) as e:
        print(f"  ✗ Нельзя создать Shape: {type(e).__name__}")
    
    print("\n" + "=" * 50)
    print("Задача 5 завершена")
    print("=" * 50)
    
if __name__ == "__main__":
    task1()
    # task2()
    # task3()
    # task4()
    # task5()