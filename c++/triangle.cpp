#include <cmath>
#include <iostream>

int main() {
  float ax, ay, bx, by, cx, cy;
  std::cout << "Input bx side traingle: (x y)" << std::endl;
  std::cin >> ax >> ay;
  std::cout << "Input bx side traingle: (x y)" << std::endl;
  std::cin >> bx >> by;
  std::cout << "Input by side traingle: (x y)" << std::endl;
  std::cin >> cx >> cy;

  float ab = std::sqrt(pow(ax - bx, 2) + pow(ay - by, 2));  // AB
  float bc = std::sqrt(pow(bx - cx, 2) + pow(by - cy, 2));  // BC
  float ca = std::sqrt(pow(cx - ax, 2) + pow(cy - ay, 2));  // CA

  float P = ab + bc + ca;                                   // Периметр
  float p = P / 2;                                          // Полупериметр
  float S = std::sqrt(p * (p - ab) * (p - bc) * (p - ca));  // Площадь

  std::cout << "ax: " << ax << std::endl;
  std::cout << "ay: " << ay << std::endl;
  std::cout << "bx: " << bx << std::endl;
  std::cout << "by: " << by << std::endl;
  std::cout << "cx: " << cx << std::endl;
  std::cout << "cy: " << cy << std::endl;

  std::cout << "side AB: " << ab << std::endl;
  std::cout << "side BC: " << bc << std::endl;
  std::cout << "side CA: " << ca << std::endl;

  std::cout << "Perimeter =  " << P << std::endl;
  std::cout << "Square =  " << S << std::endl;
}
