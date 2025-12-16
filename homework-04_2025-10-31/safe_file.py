import logging

class SafeFile:
    def __init__(self, filename, mode='r'):
        self.filename = filename
        self.mode = mode
        self.file = None
        logging.basicConfig(
            level=logging.ERROR,
            format='%(asctime)s - %(levelname)s - %(message)s',
            handlers=[
                logging.FileHandler('safe-file.log'),
                # logging.StreamHandler() - раскомментировать, если хотим дублировать лог в консоль
            ]
        )
    
    def __enter__(self):
        try:
            self.file = open(self.filename, self.mode)
            return self.file
        except Exception as e:
            logging.error(f"Ошибка при открытии файла {self.filename}: {e}")
            return None
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        if self.file:
            self.file.close()
        if exc_type:
            logging.error(f"Ошибка в контексте: {exc_val}")
        return True