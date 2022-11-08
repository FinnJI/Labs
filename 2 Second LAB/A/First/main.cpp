#include <iostream>
#include <math.h>

using namespace std;
// Определение границ
const int x1 = -3;
const int x2 = 0;
const int x3 = 6;

int main(){
  double x, y;

  // Ввод x
  cout << "Enter x: ";
  cin >> x;

  if (x < x1) 		     y = x+3;
  if (x >= x1 && x < x2) y = sqrt(9-x*x);
  if (x >= x2 && x < x3) y = -0.5*x+3;
  if (x >= x3) 		     y = x-6;

  // Вывод
  cout << "x = " << x << '\t' << "y = " << y << '\n';
  return 0;
}
