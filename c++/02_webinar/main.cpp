#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double v1, a1, v2, a2, s;
  cin >> v1 >> a1 >> v2 >> a2 >> s;

  double a = (a1 + a2) / 2.0;
  double b = v1 + v2;
  double d = b * b + 4 * a * s;

  if (d < 0 || (a == 0 && b == 0)) {
    cout << -1 << endl;  // Проверка на невозможность решения
    return 0;
  }

  double t;
  if (a == 0) {
    t = s / b;  // Если ускорение нулевое, используем линейную формулу
  } else {
    t = (-b + sqrt(d)) / (2 * a);
  }

  if (t < 0) {
    cout << -1 << endl;  // Время не может быть отрицательным
  } else {
    cout << static_cast<int>(t + 1e-9) << endl;  // Корректное округление
  }

  return 0;
}
