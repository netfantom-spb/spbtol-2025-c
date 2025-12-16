class Temperature:
    def __init__(self, celsius: float):
        self.celsius = celsius
    
    @staticmethod
    def from_fahrenheit(f: float) -> 'Temperature':
        return Temperature((f - 32) * 5 / 9)
    
    @staticmethod
    def from_kelvin(k: float) -> 'Temperature':
        return Temperature(k - 273.15)
    
    def __add__(self, other):
        if isinstance(other, Temperature):
            return Temperature(self.celsius + other.celsius)
        elif isinstance(other, (int, float)):
            return Temperature(self.celsius + other)
        return NotImplemented
    
    def __sub__(self, other):
        if isinstance(other, Temperature):
            return Temperature(self.celsius - other.celsius)
        elif isinstance(other, (int, float)):
            return Temperature(self.celsius - other)
        return NotImplemented
    
    def __repr__(self) -> str:
        #  f"Temperature({self.celsius:.2f}°C)"
        return f"{self.__class__.__name__}({self.celsius:.2f})"