from course import Course

class PremiumCourse(Course):
    def __init__(self, title: str, duration: int, mentor: str):
        super().__init__(title, duration)
        self.__mentor = mentor
    
    @property
    def mentor(self) -> str:
        return self.__mentor
    
    def get_info(self) -> str:
        base_info = super().get_info()
        return f"{base_info}, Наставник: {self.__mentor}"