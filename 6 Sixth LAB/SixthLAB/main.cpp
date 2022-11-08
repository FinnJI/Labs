#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "������� n: ";
    cin >> n;
    cout << endl;

    //����������� �� ��������

    Matrix a(n, 0);
    cout << endl;

    //������������� �����������

    Matrix b(n, 0.0);
    b.print();
    cout << endl;

    //����������� ��������� �������

    Matrix c(n);
    c.print();
    cout << endl;

    //������

    a.maximumElement();
    a.minimumElement();
    a.spur();
    cout << endl;
    a.rowSwap(0,1);
    cout << "���������� ������:" <<endl;
    a.print();

    return 0;
}
