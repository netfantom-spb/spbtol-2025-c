from car import Car
from temperature import Temperature
from student import Student
from rectangle import Rectangle
from library import Library

def task1():
    print("=" * 50)
    print("ЗАДАЧА 1: Класс Car")
    print("=" * 50)
    
    print(f"Создано машин: {Car.total_cars}")
    
    car1 = Car("Toyota", "Camry", 2015)
    car2 = Car("Lada", "Vesta", 2020)
    car3 = Car("Volga", "GAZ-24", 1978)
    
    print(f"Создано машин: {Car.total_cars}")
    print(f"{car1}")
    print(f"{car2}")
    print(f"{car3}")
    
    print("\nПроверка статического метода:")
    print(f"1950: {Car.is_vintage(1950)}")
    print(f"2000: {Car.is_vintage(2000)}")
    print(f"2023: {Car.is_vintage(2023)}")
    

    
    print("\n" + "=" * 50)
    
def task2():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 2: Класс Temperature")
    print("=" * 50)
    
    print("1. Создание температур:")
    t1 = Temperature(20)
    t2 = Temperature.from_fahrenheit(68)
    t3 = Temperature.from_kelvin(293.15)
    
    print(f"t1: {t1}")
    print(f"t2 (из 68°F): {t2}")
    print(f"t3 (из 293.15K): {t3}")
    
    print("\n2. Сложение и вычитание:")
    t_sum = t1 + t2
    print(f"t1 + t2 = {t_sum}")
    
    t_diff = t1 - 5
    print(f"t1 - 5 = {t_diff}")
    
    t_combo = t1 + t2 - 10
    print(f"t1 + t2 - 10 = {t_combo}")
    
    print("\n3. __repr__:")
    print(t1)
    
    print("\n" + "=" * 50)
    
def task3():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 3: Класс Student")
    print("=" * 50)
    
    print("1. Создание студентов:")
    s1 = Student("Иван")
    s2 = Student("Мария")
    s3 = Student("Петр")
    
    print(f"{s1}")
    print(f"{s2}")
    print(f"{s3}")
    
    print("\n2. Проверка валидации имени:")
    try:
        s4 = Student("123")
    except ValueError as e:
        print(f"Ошибка: {e}")
    
    print(f"\nСтатический метод:")
    print(f"validate_name('Анна'): {Student.validate_name('Анна')}")
    print(f"validate_name(''): {Student.validate_name('')}")
    print(f"validate_name('John123'): {Student.validate_name('John123')}")
    
    print("\n3. Проверка равенства и хэширования:")
    s1_copy = Student("Иван")
    print(f"s1 == s2: {s1 == s2}")
    print(f"s1 == s1_copy: {s1 == s1_copy}")
    print(f"Хэш s1: {hash(s1)}, Хэш s2: {hash(s2)}")
    
    students_set = {s1, s2, s3}
    print(f"Студенты в множестве: {students_set}")
    
    print("\n" + "=" * 50)

def task4():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 4: Класс Rectangle")
    print("=" * 50)
    
    print(f"Создано прямоугольников: {Rectangle.count}")
    
    print("\n1. Создание прямоугольников:")
    r1 = Rectangle(5, 3)
    r2 = Rectangle(4, 4)
    
    print(f"r1: {r1}")
    print(f"r2: {r2}")
    print(f"Создано прямоугольников: {Rectangle.count}")
    
    print("\n2. Площадь:")
    print(f"Площадь r1: {r1.area}")
    print(f"Площадь r2: {r2.area}")
    
    print("\n3. Статический метод is_square:")
    print(f"r1 (5x3) квадрат? {Rectangle.is_square(5, 3)}")
    print(f"r2 (4x4) квадрат? {Rectangle.is_square(4, 4)}")
    
    print("\n4. Умножение (масштабирование):")
    r3 = r1 * 2
    print(f"r1 * 2 = {r3}")
    print(f"Площадь r3: {r3.area}")
    
    print("\n5. Проверка валидации:")
    try:
        r4 = Rectangle(-2, 5)
    except ValueError as e:
        print(f"Ошибка: {e}")
    
    try:
        r5 = r1 * -1
    except ValueError as e:
        print(f"Ошибка умножения: {e}")
    
    print(f"\nИтог: создано прямоугольников: {Rectangle.count}")
    print("\n" + "=" * 50)
    
def task5():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 5: Класс Library")
    print("=" * 50)
    
    print(f"Книг в библиотеке: {len(Library())}")
    
    lib = Library()
    
    print("\n1. Добавление книг:")
    lib.add_book("Война и мир", "Л. Толстой")
    lib.add_book("Преступление и наказание", "Ф. Достоевский")
    lib.add_book("Мастер и Маргарита", "М. Булгаков")
    # или если мы объявили add_book статическим методом
    # Library.add_book("Война и мир", "Л. Толстой")
    # Library.add_book("Преступление и наказание", "Ф. Достоевский")
    # Library.add_book("Мастер и Маргарита", "М. Булгаков")
    
 
    print(f"Книг в библиотеке: {len(lib)}")
    
    print("\n2. Форматирование книги:")
    print(f"Формат: {Library.format_book_info('1984', 'Дж. Оруэлл')}")
    
    print("\n3. Доступ по индексу:")
    print(f"Первая книга: {lib[0]}")
    print(f"Форматированно: {Library.format_book_info(lib[0]['title'], lib[0]['author'])}")
    
    print("\n4. Проверка наличия (__contains__):")
    print(f"Есть 'Война и мир'? {'Война и мир' in lib}")
    print(f"Есть 'Гарри Поттер'? {'Гарри Поттер' in lib}")
    
    print("\n5. Перебор книг:")
    for i, book in enumerate(Library.books, 1):
        print(f"{i}. {Library.format_book_info(book['title'], book['author'])}")
    
    print(f"\n{lib}")
    print("\n" + "=" * 50)

if __name__ == "__main__":
    task1()
    task2()
    task3()
    task4()
    task5()