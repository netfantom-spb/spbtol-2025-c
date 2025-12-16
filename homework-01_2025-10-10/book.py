import datetime

class Book:
    """Класс Книга с валидацией года издания"""
    
    def __init__(self, title: str, author: str, year: int):
        """
        Конструктор класса Book
        
        Args:
            title: Название книги
            author: Автор книги
            year: Год издания
        """
        self.__title = title
        self.__author = author
        self.year = year  # Используем сеттер для валидации
    
    @property
    def title(self) -> str:
        """Геттер для названия книги (только чтение)"""
        return self.__title
    
    @property
    def author(self) -> str:
        """Геттер для автора книги (только чтение)"""
        return self.__author
    
    @property
    def year(self) -> int:
        """Геттер для года издания"""
        return self.__year
    
    @year.setter
    def year(self, value: int):
        """Сеттер для года издания с валидацией"""
        current_year = datetime.datetime.now().year
        
        if not isinstance(value, int):
            raise TypeError("Год издания должен быть целым числом")
        
        if value < 1 or value > current_year:
            raise ValueError(f"Год издания должен быть в диапазоне от 1 до {current_year}")
        
        self.__year = value
    
    def display_info(self) -> None:
        """Выводит информацию о книге"""
        print(f"Название: {self.__title}")
        print(f"Автор: {self.__author}")
        print(f"Год издания: {self.__year}")
    
    def __str__(self) -> str:
        """Строковое представление книги"""
        return f"'{self.__title}' - {self.__author} ({self.__year})"