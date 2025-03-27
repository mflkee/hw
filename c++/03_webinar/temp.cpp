#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> temperatures(2 * N);
  for (int i = 0; i < 2 * N; ++i) {
    cin >> temperatures[i];
  }

  // Поиск дня с минимальной разницей температур
  int min_diff = abs(temperatures[0] - temperatures[1]);
  int min_day = 1;
  for (int i = 1; i < N; ++i) {
    int diff = abs(temperatures[2 * i] - temperatures[2 * i + 1]);
    if (diff < min_diff) {
      min_diff = diff;
      min_day = i + 1;
    }
  }
  cout << min_day << endl;

  // Формирование массива положительных дневных температур
  vector<int> positive_temps;
  for (int i = 0; i < N; ++i) {
    if (temperatures[2 * i] > 0) {
      positive_temps.push_back(temperatures[2 * i]);
    }
  }

  if (positive_temps.empty()) {
    cout << "No positive data" << endl;
  } else if ((int)positive_temps.size() == N) {  // Если количество положительных равно N, значит все положительные
    cout << "All data are positive" << endl;
  } else {
    for (int temp : positive_temps) {
      cout << temp << " ";
    }
    cout << endl;
  }

  return 0;
}
