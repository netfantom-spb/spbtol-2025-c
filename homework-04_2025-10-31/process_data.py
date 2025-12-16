def process_data(data):
    if not isinstance(data, list):
        raise TypeError("Данные должны быть списком")
    if len(data) == 0:
        raise ValueError("Список не может быть пустым")
    for item in data:
        if not isinstance(item, (int, float)):
            raise TypeError(f"Элемент '{item}' не является числом")
    
    result = sum(item * 2 for item in data)
    return result
    