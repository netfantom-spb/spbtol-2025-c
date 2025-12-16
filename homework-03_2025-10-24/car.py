class Car:
    total_cars = 0
    
    def __init__(self, brand: str, model: str, year: int):
        self.brand = brand
        self.model = model
        self.year = year
        Car.total_cars += 1
    
    @staticmethod
    def is_vintage(year: int) -> bool:
        return (2025 - year) > 30
    
    def __str__(self) -> str:
        return f"Car({self.brand}={self.model}, year={self.year})"