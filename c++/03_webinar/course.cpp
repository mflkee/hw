#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Date {
  int day, month, year;

  void add_days(int days) {
    static const int days_in_month[] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};
    day += days;
    while (true) {
      int max_days =
          (month == 2 && is_leap_year(year)) ? 29 : days_in_month[month - 1];
      if (day <= max_days)
        break;
      day -= max_days;
      if (++month > 12) {
        month = 1;
        year++;
      }
    }
  }

  static bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }

  string to_string() const {
    ostringstream oss;
    oss << setw(2) << setfill('0') << day << "." << setw(2) << setfill('0')
        << month << "." << year;
    return oss.str();
  }
};

int main() {
  int d, m, y, n;
  cin >> d >> m >> y;
  cin >> n;
  vector<double> rates(n);
  for (double &rate : rates)
    cin >> rate;

  int max_index = 0;
  for (int i = 1; i < n; i++) {
    if (rates[i] > rates[max_index]) {
      max_index = i;
    }
  }

  int growth_days = 0;
  for (int i = max_index - 1; i >= 0; i--) {
    if (rates[i] < rates[i + 1])
      growth_days++;
    else
      break;
  }

  Date max_date = {d, m, y};
  max_date.add_days(max_index);

  cout << max_date.to_string() << " " << growth_days << endl;
  return 0;
}
