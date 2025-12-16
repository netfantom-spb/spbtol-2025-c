class BankAccount:
    """
    Класс Банковский счёт с защитой баланса.
    
    Attributes:
        balance (float): Текущий баланс счёта (только для чтения)
    """
    
    def __init__(self, initial_balance: float = 0.0):
        """
        Инициализирует банковский счёт.
        
        Args:
            initial_balance: Начальный баланс счёта
            
        Raises:
            ValueError: Если начальный баланс отрицательный
        """
        if initial_balance < 0:
            raise ValueError("Начальный баланс не может быть отрицательным")
        self.__balance = initial_balance
        print(f"Счёт создан. Начальный баланс: {initial_balance:.2f} руб.")
    
    def deposit(self, amount: float) -> None:
        """
        Пополняет счёт на указанную сумму.
        
        Args:
            amount: Сумма для пополнения
            
        Raises:
            ValueError: Если сумма пополнения отрицательная или равна нулю
        """
        if amount <= 0:
            raise ValueError("Сумма пополнения должна быть положительной")
        self.__balance += amount
        print(f"Пополнено: {amount:.2f} руб. Новый баланс: {self.__balance:.2f} руб.")
    
    def withdraw(self, amount: float) -> bool:
        """
        Снимает средства со счёта.
        
        Args:
            amount: Сумма для снятия
            
        Returns:
            True если снятие успешно, False если недостаточно средств
            
        Raises:
            ValueError: Если сумма снятия отрицательная или равна нулю
        """
        if amount <= 0:
            raise ValueError("Сумма снятия должна быть положительной")
        
        if amount > self.__balance:
            print(f"Ошибка: Недостаточно средств. Запрошено: {amount:.2f}, доступно: {self.__balance:.2f} руб.")
            return False
        
        self.__balance -= amount
        print(f"Снято: {amount:.2f} руб. Новый баланс: {self.__balance:.2f} руб.")
        return True
    
    @property
    def balance(self) -> float:
        """
        Возвращает текущий баланс счёта.
        
        Returns:
            Текущий баланс счёта
        """
        return self.__balance
    
    def __del__(self):
        """
        Деструктор. Вызывается при удалении объекта.
        """
        if hasattr(self, '_BankAccount__balance'):
            print(f"Счёт закрыт. Остаток: {self.__balance:.2f} руб.")