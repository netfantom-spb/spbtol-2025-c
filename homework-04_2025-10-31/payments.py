# payments.py
from abc import ABC, abstractmethod

class PaymentProcessor(ABC):
    @abstractmethod
    def validate_payment(self, data):
        pass
    
    @abstractmethod
    def process_payment(self, amount: float):
        pass

class CreditCardProcessor(PaymentProcessor):
    def __init__(self, card_number, cvv):
        self.card_number = card_number
        self.cvv = cvv
    
    def validate_payment(self, data):
        if not (len(self.card_number) == 16 and self.card_number.isdigit()):
            raise ValueError("Номер карты должен содержать 16 цифр")
        if not (len(self.cvv) == 3 and self.cvv.isdigit()):
            raise ValueError("CVV должен содержать 3 цифры")
        return True
    
    def process_payment(self, amount: float):
        self.validate_payment(None)
        print(f"Оплата картой ***{self.card_number[-4:]} на сумму {amount:.2f} прошла успешно")

class PayPalProcessor(PaymentProcessor):
    def __init__(self, email):
        self.email = email
    
    def validate_payment(self, data):
        if "@" not in self.email:
            raise ValueError("Некорректный email адрес")
        return True
    
    def process_payment(self, amount: float):
        self.validate_payment(None)
        print(f"PayPal перевод на {self.email} на сумму {amount:.2f} выполнен")

class CryptoProcessor(PaymentProcessor):
    def __init__(self, wallet_address):
        self.wallet_address = wallet_address
    
    def validate_payment(self, data):
        if not self.wallet_address.startswith("bc1"):
            raise ValueError("Адрес кошелька должен начинаться с bc1")
        return True
    
    def process_payment(self, amount: float):
        self.validate_payment(None)
        print(f"Криптоплатеж на адрес {self.wallet_address} на сумму {amount:.2f} BTC подтвержден")