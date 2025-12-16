from bank_account import BankAccount
from savings_account import SavingsAccount
from course import Course
from premium_course import PremiumCourse
from animal import Animal
from pet_animal import PetAnimal
from rectangle import Rectangle
from square import Square
from user import User
from admin import Admin


def task1():
    print("=" * 50)
    print("ЗАДАЧА 1: Банковские счета")
    print("=" * 50)
    
    # Базовый счет
    print("\n1. Базовый счет:")
    acc1 = BankAccount(1000)
    print("Баланс:", acc1.balance)
    acc1.deposit(500)
    print("После пополнения:", acc1.balance)
    acc1.display_info()
    
    # Сберегательный счет
    print("\n2. Сберегательный счет:")
    acc2 = SavingsAccount(2000, 5.5)
    print("Баланс:", acc2.balance)
    print("Ставка:", acc2.interest_rate)
    acc2.display_info()
    
    # Демонстрация наследования
    print("\n3. Наследование методов:")
    acc2.deposit(1000)
    print("После пополнения:", acc2.balance)
    
    print("\n" + "=" * 50)
    
def task2():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 2: Обучающие курсы")
    print("=" * 50)
    
    print("\n1. Базовый курс:")
    course1 = Course("Python Basics", 40)
    print(course1.get_info())
    print("Название:", course1.title)
    print("Длительность:", course1.duration)
    
    print("\n2. Премиум курс:")
    course2 = PremiumCourse("Python Advanced", 60, "Алексей Иванов")
    print(course2.get_info())
    print("Наставник:", course2.mentor)
    print("Название:", course2.title)
    print("Длительность:", course2.duration)
    
    print("\n" + "=" * 50)

def task3():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 3: Животные")
    print("=" * 50)
    
    print("\n1. Базовое животное:")
    animal = Animal("Лев")
    print(animal.display_info())
    print("Звук:", animal.make_sound())
    
    print("\n2. Домашний питомец:")
    pet = PetAnimal("Барсик", "Мария")
    print(pet.display_info())
    print("Звук:", pet.make_sound())
    print("Владелец:", pet.owner)
    
    print("\n" + "=" * 50)
    
def task4():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 4: Геометрические фигуры")
    print("=" * 50)
    
    print("\n1. Прямоугольник:")
    rect = Rectangle(5, 3)
    print(f"Ширина: {rect.width}, Высота: {rect.height}")
    print(f"Площадь: {rect.area}")
    
    print("\n2. Квадрат:")
    square = Square(4)
    print(f"Сторона: {square.side}")
    print(f"Площадь: {square.area}")
    print(f"Ширина: {square.width}, Высота: {square.height}")
    
    print("\n" + "=" * 50)
    
def task5():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 5: Пользователи системы")
    print("=" * 50)
    
    print("\n1. Обычный пользователь:")
    user = User("ivan_ivanov", "ivan@mail.ru")
    print(user.display_info())
    print(f"Username: {user.username}, Email: {user.email}")
    
    print("\n2. Администратор:")
    admin = Admin("admin", "admin@system.com", 2)
    print(admin.display_info())
    print(f"Уровень доступа: {admin.admin_level}")
    
    print("\n3. Тест валидации уровня:")
    try:
        Admin("bad_admin", "bad@mail.com", 5)
    except ValueError as e:
        print(f"Ошибка: {e}")
    
    print("\n" + "=" * 50)
        
if __name__ == "__main__":
    task1()
    task2()
    task3()
    task4()
    task5()
    