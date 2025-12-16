class User:
    def __init__(self, username: str, email: str):
        self.__username = username
        self.__email = email
    
    @property
    def username(self) -> str:
        return self.__username
    
    @property
    def email(self) -> str:
        return self.__email
    
    def display_info(self) -> str:
        return f"Пользователь: {self.__username}, Email: {self.__email}"