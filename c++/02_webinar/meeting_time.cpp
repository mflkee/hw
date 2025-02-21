#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Проверка деления на ноль
bool zerodiv(double a1, double a2) {
  return a1 + a2 != 0;
}

// Проверка дискриминанта
bool zerodisc(double disc) {
  return disc >= 0;
}

// Проверка корректности расстояния
bool zerodist(double S) {
  return S >= 0;
}

// Вычисление времени встречи
double calctime(double v1, double a1, double v2, double a2, double S) {
  double vsum = v1 + v2;  // Сумма скоростей
  double asum = a1 + a2;  // Сумма ускорений

  // Проверка расстояния
  if (!zerodist(S)) {
    cout << "Ошибка: расстояние не может быть отрицательным." << endl;
    return -1;
  }

  // Если сумма ускорений равна нулю, проверяем сумму скоростей
  if (!zerodiv(a1, a2)) {
    if (vsum != 0) {
      return trunc(S / vsum);  // Время для равномерного движения
    }
    cout << "Ошибка: сумма ускорений и скоростей равна нулю." << endl;
    return -1;
  }

  // Вычисление дискриминанта
  double disc = pow(vsum, 2) + 2 * asum * S;

  // Проверка дискриминанта
  if (!zerodisc(disc)) {
    cout << "Ошибка: дискриминант меньше нуля." << endl;
    return -1;
  }

  // Вычисление времени встречи
  return trunc((-vsum + sqrt(disc)) / asum);
}

// Функция для запуска тестов
void test_run() {
  struct testcase {
    double v1, a1, v2, a2, S;  // Входные данные
    double expected;           // Ожидаемый результат
  };

  // Набор тестовых данных
  vector<testcase> testcases = {
      {0, 0, 1, 0, 100, 100},
      {1, 0.5, 2, 0.25, 100, 12},
      {1, 1, 1, 1, 200, 13},
  };

  // Проходим по всем тестам
  for (size_t i = 0; i < testcases.size(); ++i) {
    const testcase& test = testcases[i];
    double result        = calctime(test.v1, test.a1, test.v2, test.a2, test.S);

    // Проверяем результат
    if (result == test.expected) {
      cout << "Тест " << i + 1 << ": УСПЕШНО" << endl;
    } else {
      cout << "Тест " << i + 1 << ": ОШИБКА" << endl;
      cout << " Входные данные: v1=" << test.v1 << ", a1=" << test.a1
           << ", v2=" << test.v2 << ", a2=" << test.a2 << ", S=" << test.S
           << endl;
      cout << " Ожидалось: " << test.expected << ", Получено: " << result
           << endl;
    }
  }
}

int main() {
  // char testmode;
  // cout << "Активировать тестовый режим? (y/n): ";
  // cin >> testmode;

  // // Запуск тестового режима
  // if (testmode == 'y' || testmode == 'Y') {
  //   test_run();
  //   return 0;
  // }

  // Основная программа
  double v1, a1, v2, a2, S;
  cout << "Введите данные в следующем формате и порядке:" << endl;
  cout << "v1(м/с) a1(м/с^2) v2(м/с) a2(м/с^2) S(м):" << endl;
  cin >> v1 >> a1 >> v2 >> a2 >> S;

  double time = calctime(v1, a1, v2, a2, S);

  if (time == -1) {
    cout << "Ошибка: тела не встретятся." << endl;
  } else {
    cout << time << endl;
  }

  return 0;
}
