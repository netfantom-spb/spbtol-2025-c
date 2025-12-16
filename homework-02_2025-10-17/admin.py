from user import User

class Admin(User):
    def __init__(self, username: str, email: str, admin_level: int):
        super().__init__(username, email)
        if admin_level not in (1, 2, 3):
            raise ValueError("Уровень администратора должен быть 1, 2 или 3")
        self.__admin_level = admin_level
    
    @property
    def admin_level(self) -> int:
        return self.__admin_level
    
    def display_info(self) -> str:
        base_info = super().display_info()
        return f"{base_info}, Уровень доступа: {self.__admin_level}"