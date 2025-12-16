class Student:
    """
    Класс Студент с динамическим списком оценок.
    
    Attributes:
        name (str): Имя студента
        grades (list): Список оценок
        average_grade (float): Средний балл (свойство только для чтения)
    """
    
    def __init__(self, name: str):
        """
        Инициализирует студента.
        
        Args:
            name: Имя студента
        """
        self.__name = name
        self.__grades = []
        print(f"Создан студент: {name}")
    
    def add_grade(self, grade: int) -> None:
        """
        Добавляет оценку студенту.
        
        Args:
            grade: Оценка (от 1 до 5)
            
        Raises:
            ValueError: Если оценка вне диапазона 1-5
        """
        if not 1 <= grade <= 5:
            raise ValueError(f"Оценка должна быть от 1 до 5, получено: {grade}")
        
        self.__grades.append(grade)
        print(f"  Добавлена оценка {grade} для {self.__name}")
    
    @property
    def name(self) -> str:
        """Имя студента (только чтение)"""
        return self.__name
    
    @property
    def average_grade(self) -> float:
        """Средний балл студента"""
        if not self.__grades:
            return 0.0
        
        return sum(self.__grades) / len(self.__grades)
    
    @property
    def grades(self) -> list:
        """Копия списка оценок (только чтение)"""
        return self.__grades.copy()
    
    def __str__(self) -> str:
        """Строковое представление студента"""
        avg = self.average_grade
        return f"Студент: {self.__name}, Средний балл: {avg:.2f}"