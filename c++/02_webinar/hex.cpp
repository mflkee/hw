#include <iostream>
#include <cmath>
using namespace std;

void digit_swap(int *N){
  int quantity = log10(*N) + 1;
  cout << quantity << endl;
  
}

int main() {
  int N;
  cin >> N;

  int d = 0;
  for (int temp = N; temp > 0; temp /= 16)
    d = max(d, temp % 16);
  cout << d << endl;

  if (0 <= d && d <= 9)
    N *= 2;
  if (d == 10 || d == 13)
   N /= 10;
  if (d == 11 || d == 12)
    digit_swap(&N);
    
}
