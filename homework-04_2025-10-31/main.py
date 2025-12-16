from notifications import EmailService,SMSService,PushService
from payments import CreditCardProcessor, CryptoProcessor, PayPalProcessor
from process_data import process_data
from safe_file import SafeFile


def task1():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 1: notifier") 
    print("=" * 50)
    message: str = "Ваш заказ готов!"
    services = [EmailService(), SMSService(), PushService()]
    for service in services:
        service.send(message)
    print("=" * 50)
        
def task2():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 2: Оплаты") 
    print("=" * 50)
    try:
        card = CreditCardProcessor("1234567890123456", "123")
        card.process_payment(100.50)
    except ValueError as e:
        print(f"Ошибка карты: {e}")
        
    try:
        card = CreditCardProcessor("123", "123")
        card.process_payment(100.50)
    except ValueError as e:
        print(f"Ошибка карты: {e}")
    
    try:
        paypal = PayPalProcessor("user@mail.ru")
        paypal.process_payment(75.25)
    except ValueError as e:
        print(f"Ошибка PayPal: {e}")
    
    try:
        crypto = CryptoProcessor("bc1qar0srrr7xfkvy5l643lydnw9re59gtzzwf5mdq")
        crypto.process_payment(0.005)
    except ValueError as e:
        print(f"Ошибка крипто: {e}")
    
    # Ошибочные платежи
    print("\nТест ошибочных данных:")
    
    try:
        bad_card = CreditCardProcessor("123", "12")
        bad_card.process_payment(50.00)
    except ValueError as e:
        print(f"Ошибка карты: {e}")
    
    try:
        bad_paypal = PayPalProcessor("invalid-email")
        bad_paypal.process_payment(30.00)
    except ValueError as e:
        print(f"Ошибка PayPal: {e}")
    
    try:
        bad_crypto = CryptoProcessor("0x123abc")
        bad_crypto.process_payment(0.01)
    except ValueError as e:
        print(f"Ошибка крипто: {e}")
    
    print("=" * 50)
        
def task3():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 3: process_data") 
    print("=" * 50)
    test_cases = [
        [1, 2, 3],
        "not a list",
        [],
        [1, "two", 3]
    ]
    for test_data in test_cases:
        print(f"data: {test_data}")
        try:
            process_data(test_data)
        except TypeError as e:
            print(f"Ошибка типа: {e}")
        except ValueError as e:
            print(f"Ошибка значения: {e}")
        except Exception as e:
            print(f"Неизвестная ошибка: {e}")
        finally:
            print(f"Операция завершена\n")
    print("\n" + "=" * 50)
    
def task4():
    print("\n" + "=" * 50)
    print("ЗАДАЧА 4: safe-file") 
    print("=" * 50)
    with SafeFile("test.txt") as f:
        if f:
            content = f.read()
            print(content)
    
    with SafeFile("nonexistent.txt") as f:
        if f is None:
            print("Файл не был открыт, продолжаем выполнение")
    print("\n" + "=" * 50)

if __name__ == "__main__":
    task1()
    task2()
    task3()
    task4()