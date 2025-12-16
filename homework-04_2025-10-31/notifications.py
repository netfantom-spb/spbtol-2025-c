from abc import ABC, abstractmethod

class NotificationService(ABC):
    @abstractmethod
    def send(self, message: str):
        pass

class EmailService(NotificationService):
    def send(self, message: str):
        print(f"[Email] Отправлено: {message}")

class SMSService(NotificationService):
    def send(self, message: str):
        print(f"[SMS] Отправлено: {message}")

class PushService(NotificationService):
    def send(self, message: str):
        print(f"[Push] Отправлено: {message}")

