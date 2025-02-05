def min_breaks(n, m):
    # базовые случаи
    if n == 1 and m == 1:
        return 0
    if n == 1:
        return m - 1
    if m == 1:
        return n - 1
    # ркурсивный метод для больших плиток
    if n < m:
        # оптимизация, для скорейшего перехода в базовый вид
        # Делить n пополам
        return min_breaks(n // 2, m) + min_breaks(n - n // 2, m) + 1
    else:
        # Делить m пополам
        return min_breaks(n, m // 2) + min_breaks(n, m - m // 2) + 1


# Тестирование
print(min_breaks(2, 3))  # Должно вывести 5
print(min_breaks(3, 3))  # Должно вывести 8
print(min_breaks(1, 1))  # Должно вывести 0
print(min_breaks(4, 2))  # Должно вывести 7
