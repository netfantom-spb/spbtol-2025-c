class Course:
    def __init__(self, title: str, duration: int):
        self.__title = title
        if duration <= 0:
            raise ValueError("Длительность должна быть положительной")
        self.__duration = duration
    
    @property
    def title(self) -> str:
        return self.__title
    
    @property
    def duration(self) -> int:
        return self.__duration
    
    def get_info(self) -> str:
        return f"Курс: {self.__title}, Длительность: {self.__duration} часов"