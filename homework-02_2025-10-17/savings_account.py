from bank_account import BankAccount

class SavingsAccount(BankAccount):
    def __init__(self, initial_balance: float, interest_rate: float):
        super().__init__(initial_balance)
        if interest_rate < 0:
            raise ValueError("Процентная ставка не может быть отрицательной")
        self.__interest_rate = interest_rate
    
    @property
    def interest_rate(self) -> float:
        return self.__interest_rate
    
    def display_info(self) -> None:
        super().display_info()
        print(f"Процентная ставка: {self.__interest_rate:.1f}%")