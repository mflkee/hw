def get_prices_for_store(store_name, products):
    prices = {}
    print(f"\nВведите цены для магазина {store_name}:")
    for product in products:
        price = float(input(f"Цена для {product}: "))
        prices[product] = price
    return prices

def calculate_total(prices):
    return sum(prices.values())

def main():
    # Ввод данных от пользователя
    stores_count = int(input("Сколько магазинов вы хотите сравнить? "))
    product_count = int(input("Сколько товаров вы планируете купить? "))

    products = []
    for _ in range(product_count):
        product = input("Введите название товара: ")
        products.append(product)

    stores = {}
    for _ in range(stores_count):
        store_name = input("\nВведите название магазина: ")
        stores[store_name] = get_prices_for_store(store_name, products)

    # Подсчет стоимости в каждом магазине
    totals = {store: calculate_total(prices) for store, prices in stores.items()}

    # Вывод результатов
    print("\nСтоимость покупок в каждом магазине:")
    for store, total in totals.items():
        print(f"{store}: {total:.2f} руб.")

    # Поиск магазина с минимальной стоимостью
    cheapest_store = min(totals, key=totals.get)
    print(f"\nВы сэкономите больше всего в магазине: {cheapest_store}, стоимость: {totals[cheapest_store]:.2f} руб.")

if __name__ == "__main__":
    main()
