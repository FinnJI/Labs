#include <iostream>
using namespace std;

int main(){
  double x, y, R1, R2;

  // Ввод координат с клавиатуры
  cout << "Enter coords x and y: ";
  cin >> x >> y;

  cout << "Enter radius R1 and R2: ";
  cin >> R1 >> R2;

  // Вычисление попадания или промаха
  if ((x <= 0 && y >= 0 && x*x + y*y <= R1*R1) || (x >= 0 && y <= 0 && x*x + y*y <= R2*R2 && x*x + y*y >= R1*R1))
     cout << "In\n";
  else
     cout << "Out\n";
  return 0;
}

