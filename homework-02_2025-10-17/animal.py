class Animal:
    def __init__(self, name: str):
        self.__name = name
    
    @property
    def name(self) -> str:
        return self.__name
    
    def make_sound(self) -> str:
        return "Some sound"
    
    def display_info(self) -> str:
        return f"Имя: {self.__name}"