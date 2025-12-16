from animal import Animal

class PetAnimal(Animal):
    def __init__(self, name: str, owner: str):
        super().__init__(name)
        self.__owner = owner
    
    @property
    def owner(self) -> str:
        return self.__owner
    
    def make_sound(self) -> str:
        return f"{self.name} makes a cute sound"
    
    def display_info(self) -> str:
        base_info = super().display_info()
        return f"{base_info}, Владелец: {self.__owner}"
    