class Student:
    next_id = 1
    
    def __init__(self, name: str):
        if not self.validate_name(name):
            raise ValueError("Имя должно содержать только буквы и не быть пустым")
        self.name = name
        self.student_id = Student.next_id
        Student.next_id += 1
    
    @staticmethod
    def validate_name(name: str) -> bool:
        return isinstance(name, str) and name.isalpha() and len(name) > 0
    
    def __eq__(self, other):
        if isinstance(other, Student):
            return self.student_id == other.student_id
        return False
    
    def __hash__(self):
        return hash(self.student_id)
    
    def __repr__(self) -> str:
        return f"Student({self.name}, id={self.student_id})"