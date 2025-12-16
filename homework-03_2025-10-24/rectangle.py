class Rectangle:
    count = 0
    
    def __init__(self, width: float, height: float):
        if width <= 0 or height <= 0:
            raise ValueError("Ширина и высота должны быть положительными")
        self.width = width
        self.height = height
        Rectangle.count += 1
    
    @property
    def area(self) -> float:
        return self.width * self.height
    
    @staticmethod
    def is_square(width: float, height: float) -> bool:
        return width == height
    
    def __mul__(self, factor: float):
        if factor <= 0:
            raise ValueError("Коэффициент должен быть положительным")
        return Rectangle(self.width * factor, self.height * factor)
    
    def __repr__(self) -> str:
        return f"Rectangle({self.width}x{self.height})"