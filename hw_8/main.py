import pandas as pd

INPUT_FILE = "web_clients_correct.csv"  # Исходный CSV-файл
OUTPUT_FILE = "clients_descriptions.txt"  # Результирующий TXT-файл


def load_data(file_path):
    """
    Загружает данные из CSV-файла в DataFrame.
    """
    try:
        data = pd.read_csv(file_path)
        print("Данные успешно загружены!")
        return data
    except Exception as e:
        print(f"Ошибка загрузки данных: {e}")
        return None


def parse_and_transform_data(row):
    """
    Преобразует строку данных в текстовое описание по шаблону.
    """
    # Преобразование пола
    gender = "мужского" if row["sex"].lower() == "male" else "женского"

    # Определение типа устройства
    device_type_map = {
        "mobile": "мобильного",
        "tablet": "планшетного",
        "laptop": "ноутбука",
        "desktop": "настольного",
    }
    device = device_type_map.get(row["device_type"].lower(), "неизвестного устройства")

    # Шаблон для генерации описания
    description = (
        f"Пользователь {row['name']} {gender} пола, {row['age']} лет "
        f"совершил(а) покупку на {row['bill']} у.е. с {device} браузера {row['browser']}. "
        f"Регион, из которого совершалась покупка: {row['region']}."
    )
    return description


def generate_descriptions(data, output_file):
    """
    Генерирует описания пользователей и записывает их в текстовый файл.
    """
    try:
        descriptions = []  # Список для текстовых описаний
        for _, row in data.iterrows():
            description = parse_and_transform_data(row)
            descriptions.append(description)

        # Запись в TXT-файл
        with open(output_file, "w", encoding="utf-8") as f:
            for desc in descriptions:
                f.write(desc + "\n")
        print(f"Описание пользователей записано в файл: {output_file}")
    except Exception as e:
        print(f"Ошибка генерации описаний: {e}")


def main():
    # Шаг 1: Загрузить данные
    data = load_data(INPUT_FILE)
    if data is None:
        return

    # Проверка заголовков
    print("Заголовки столбцов:", data.columns.tolist())

    # Шаг 2: Генерация описаний и запись в файл
    generate_descriptions(data, OUTPUT_FILE)


# Запуск программы
if __name__ == "__main__":
    main()
