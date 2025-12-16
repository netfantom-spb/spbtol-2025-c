class Car:
    """
    Класс Автомобиль с ограничением скорости.
    
    Attributes:
        brand (str): Марка автомобиля
        model (str): Модель автомобиля
        speed (float): Текущая скорость (с ограничением)
        max_speed (float): Максимальная допустимая скорость
    """
    
    def __init__(self, brand: str, model: str, max_speed: float = 180.0):
        """
        Инициализирует автомобиль.
        
        Args:
            brand: Марка автомобиля
            model: Модель автомобиля
            max_speed: Максимальная скорость (должна быть положительной)
            
        Raises:
            ValueError: Если max_speed не положительная
        """
        if max_speed <= 0:
            raise ValueError("Максимальная скорость должна быть положительной")
        
        self.__brand = brand
        self.__model = model
        self.__max_speed = max_speed
        self.__speed = 0.0  # Начальная скорость
        
        print(f"Создан автомобиль: {brand} {model} (max: {max_speed} км/ч)")
    
    @property
    def brand(self) -> str:
        """Марка автомобиля (только чтение)"""
        return self.__brand
    
    @property
    def model(self) -> str:
        """Модель автомобиля (только чтение)"""
        return self.__model
    
    @property
    def max_speed(self) -> float:
        """Максимальная скорость (только чтение)"""
        return self.__max_speed
    
    @property
    def speed(self) -> float:
        """Текущая скорость (геттер)"""
        return self.__speed
    
    @speed.setter
    def speed(self, value: float):
        """
        Устанавливает скорость с валидацией.
        
        Args:
            value: Новая скорость
            
        Raises:
            ValueError: Если скорость отрицательная или превышает максимум
        """
        if value < 0:
            raise ValueError("Скорость не может быть отрицательной")
        
        if value > self.__max_speed:
            raise ValueError(f"Скорость {value} км/ч превышает максимум {self.__max_speed} км/ч")
        
        self.__speed = value
    
    def accelerate(self, delta: float) -> None:
        """
        Увеличивает скорость на указанную величину.
        
        Args:
            delta: На сколько увеличить скорость (должна быть положительной)
            
        Raises:
            ValueError: Если delta отрицательная
        """
        if delta < 0:
            raise ValueError("Ускорение не может быть отрицательным")
        
        new_speed = self.__speed + delta
        
        if new_speed > self.__max_speed:
            print(f"⚠️  Достигнут лимит скорости! Ускорение ограничено до {self.__max_speed} км/ч")
            self.__speed = self.__max_speed
        else:
            self.__speed = new_speed
            print(f"Скорость увеличена до {self.__speed:.1f} км/ч")
    
    def brake(self) -> None:
        """Полностью останавливает автомобиль."""
        if self.__speed > 0:
            print(f"⏹️  Торможение! Скорость с {self.__speed} км/ч до 0 км/ч")
            self.__speed = 0.0
        else:
            print("Автомобиль уже стоит")
    
    def __str__(self) -> str:
        """Строковое представление автомобиля."""
        return f"{self.__brand} {self.__model}: {self.__speed:.1f}/{self.__max_speed} км/ч"