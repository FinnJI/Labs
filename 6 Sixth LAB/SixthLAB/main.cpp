#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите n: ";
    cin >> n;
    cout << endl;

    //Конструктор по индексам

    Matrix a(n, 0);
    cout << endl;

    //Гененрирующий конструктор

    Matrix b(n, 0.0);
    b.print();
    cout << endl;

    //Конструктор единичной матрицы

    Matrix c(n);
    c.print();
    cout << endl;

    //Методы

    a.maximumElement();
    a.minimumElement();
    a.spur();
    cout << endl;
    a.rowSwap(0,1);
    cout << "Измененный массив:" <<endl;
    a.print();

    return 0;
}
