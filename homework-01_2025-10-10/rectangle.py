from shape import Shape

class Rectangle(Shape):
    """
    Класс Прямоугольник, наследующий Shape.
    
    Attributes:
        width (float): Ширина прямоугольника
        height (float): Высота прямоугольника
    """
    
    def __init__(self, color: str, width: float, height: float):
        """
        Инициализирует прямоугольник.
        
        Args:
            color: Цвет прямоугольника
            width: Ширина (положительное число)
            height: Высота (положительное число)
            
        Raises:
            ValueError: Если ширина или высота не положительные
        """
        super().__init__(color)
        
        if width <= 0 or height <= 0:
            raise ValueError("Ширина и высота должны быть положительными")
        
        self.__width = width
        self.__height = height
    
    @property
    def width(self) -> float:
        """Ширина прямоугольника (только чтение)"""
        return self.__width
    
    @property
    def height(self) -> float:
        """Высота прямоугольника (только чтение)"""
        return self.__height
    
    def area(self) -> float:
        """
        Вычисляет площадь прямоугольника.
        
        Returns:
            Площадь прямоугольника (ширина * высота)
        """
        return self.__width * self.__height
    
    def __str__(self) -> str:
        """Строковое представление прямоугольника."""
        return (f"Прямоугольник цвета '{self.color}', "
                f"ширина: {self.__width}, высота: {self.__height}, "
                f"площадь: {self.area():.2f}")