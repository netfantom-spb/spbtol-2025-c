from abc import ABC, abstractmethod

class Shape(ABC):
    """
    Базовый класс геометрической фигуры.
    
    Attributes:
        color (str): Цвет фигуры
    """
    
    def __init__(self, color: str):
        """
        Инициализирует фигуру.
        
        Args:
            color: Цвет фигуры (непустая строка)
            
        Raises:
            ValueError: Если цвет - пустая строка
        """
        self.color = color  # Используем сеттер для валидации
    
    @property
    def color(self) -> str:
        """Цвет фигуры (геттер)"""
        return self.__color
    
    @color.setter
    def color(self, value: str):
        """
        Устанавливает цвет фигуры.
        
        Args:
            value: Новый цвет
            
        Raises:
            ValueError: Если цвет - пустая строка
        """
        if not isinstance(value, str) or not value.strip():
            raise ValueError("Цвет должен быть непустой строкой")
        self.__color = value
    
    @abstractmethod
    def area(self) -> float:
        """
        Вычисляет площадь фигуры.
        
        Returns:
            Площадь фигуры
            
        Note:
            Абстрактный метод - должен быть реализован в подклассах
        """
        pass
    
    def info(self) -> str:
        """
        Возвращает информацию о фигуре.
        
        Returns:
            Строка с информацией о фигуре
        """
        return f"Фигура цвета '{self.color}', площадь: {self.area():.2f}"
    
    def __str__(self) -> str:
        """Строковое представление фигуры."""
        return self.info()


