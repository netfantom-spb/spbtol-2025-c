class Library:
    books = []
    
    def add_book(self, title: str, author: str):
        """Добавляет книгу в библиотеку"""
        book = {"title": title, "author": author}
        Library.books.append(book)
    
    # или если мы хотим - он может быть статическим
    @classmethod
    def add_book(cls, title: str, author: str):
        book = {"title": title, "author": author}
        cls.books.append(book)
    
    @staticmethod
    def format_book_info(title: str, author: str) -> str:
        return f'"{title}" by {author}'
    
    def __len__(self) -> int:
        return len(self.books)
    
    def __getitem__(self, index):
        return self.books[index]
    
    def __contains__(self, title: str) -> bool:
        return any(book["title"] == title for book in self.books)
    
    def __repr__(self) -> str:
        return f"Library({len(self.books)} books)"