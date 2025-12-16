import unittest
from book import Book
import datetime

class TestBook(unittest.TestCase):
    """Тесты для класса Book"""
    
    def setUp(self):
        """Подготовка тестовых данных"""
        self.current_year = datetime.datetime.now().year
        self.valid_book = Book("Тестовая книга", "Тестовый автор", 2000)
    
    def test_create_valid_book(self):
        """Тест создания книги с корректными данными"""
        book = Book("Книга", "Автор", 1999)
        self.assertEqual(book.title, "Книга")
        self.assertEqual(book.author, "Автор")
        self.assertEqual(book.year, 1999)
    
    def test_create_book_with_current_year(self):
        """Тест создания книги с текущим годом"""
        book = Book("Книга", "Автор", self.current_year)
        self.assertEqual(book.year, self.current_year)
    
    def test_create_book_with_invalid_year_future(self):
        """Тест создания книги с годом из будущего"""
        with self.assertRaises(ValueError):
            Book("Книга", "Автор", self.current_year + 1)
    
    def test_create_book_with_invalid_year_past(self):
        """Тест создания книги с годом до нашей эры (меньше 1)"""
        with self.assertRaises(ValueError):
            Book("Книга", "Автор", 0)
        with self.assertRaises(ValueError):
            Book("Книга", "Автор", -100)
    
    def test_change_year_valid(self):
        """Тест корректного изменения года издания"""
        book = Book("Книга", "Автор", 2000)
        book.year = 2005
        self.assertEqual(book.year, 2005)
    
    def test_change_year_invalid(self):
        """Тест некорректного изменения года издания"""
        book = Book("Книга", "Автор", 2000)
        with self.assertRaises(ValueError):
            book.year = self.current_year + 1
        with self.assertRaises(ValueError):
            book.year = 0
    
    def test_read_only_attributes(self):
        """Тест, что title и author доступны только для чтения"""
        book = Book("Книга", "Автор", 2000)
        
        with self.assertRaises(AttributeError):
            book.title = "Новое название"
        
        with self.assertRaises(AttributeError):
            book.author = "Новый автор"
    
    def test_display_info(self):
        """Тест метода display_info"""
        book = Book("Книга", "Автор", 2000)
        # Проверяем, что метод не вызывает исключений
        try:
            book.display_info()
        except Exception as e:
            self.fail(f"display_info вызвал исключение: {e}")
    
    def test_str_method(self):
        """Тест строкового представления"""
        book = Book("Книга", "Автор", 2000)
        expected_str = "'Книга' - Автор (2000)"
        self.assertEqual(str(book), expected_str)

if __name__ == "__main__":
    unittest.main()