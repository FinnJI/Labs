#include <iostream>
using namespace std;
int main(){
    int sz;
    int z;// 4 байта
    sz = sizeof(z);
    cout << sz << endl;
    short int a;// 2 байта
    sz = sizeof(a);
    cout << sz << endl;
    long int b;// 4 байта
    sz = sizeof(b);
    cout << sz << endl;
    long long int c;// 8 байт
    sz = sizeof(c);
    cout << sz << endl;
    float d;// 4 байта
    sz = sizeof(d);
    cout << sz << endl;
    double e;// 8 байт
    sz = sizeof(e);
    cout << sz << endl;
    long double f;// 16 байт
    sz = sizeof(f);
    cout << sz << endl;
    bool g;// 1 байт
    sz = sizeof(g);
    cout << sz << endl;
    char h;// 1 байт
    sz = sizeof(h);
    cout << sz << endl;
    wchar_t j;// 2 байта
    sz = sizeof(j);
    cout << sz << endl;
    unsigned char k;// 1 байт
    sz = sizeof(k);
    cout << sz << endl;
    unsigned short l;// 2 байта
    sz = sizeof(l);
    cout << sz << endl;
    unsigned int m;// 4 байта
    sz = sizeof(m);
    cout << sz << endl;
    unsigned long n;// 4 байта
    sz = sizeof(n);
    cout << sz << endl;
    unsigned long long o;// 8 байтов
    sz = sizeof(o);
    cout << sz << endl;
    return 0;
}

//Разницы между размерами int и unsigned int нет, поскольку в unsigned int
//вместо отрицательных чисел идёт такое же количество положительных чисел

//double - 8 байт long double - 16 байт

//char и unsigned не отличаются по размеру, так как меняется только способ нумерации
