#include <iostream>

using namespace std;

int main()
{
    int i;
    float f;
    double d;
    bool b;

    f = -1.1;
    i = int(f);
    cout << i << endl;
    i = f;
    cout << i << endl;

    f = -1.5;
    i = int(f);
    cout << i << endl;
    i = f;
    cout << i << endl;

    f = -1.9;
    i = int(f);
    cout << i << endl;
    i = f;
    cout << i << endl;

    f = 1.1;
    i = int(f);
    cout << i << endl;
    i = f;
    cout << i << endl;

    f = 1.5;
    i = int(f);
    cout << i << endl;
    i = f;
    cout << i << endl;

    f = 1.9;
    i = int(f);
    cout << i << endl;
    i = f;
    cout << i << endl;

    cout << "-----------" << endl;

    d = -1.1;
    i = int(d);
    cout << i << endl;
    i = d;
    cout << i << endl;

    d = -1.5;
    i = int(d);
    cout << i << endl;
    i = d;
    cout << i << endl;

    d = -1.9;
    i = int(d);
    cout << i << endl;
    i = d;
    cout << i << endl;

    d = 1.1;
    i = int(d);
    cout << i << endl;
    i = d;
    cout << i << endl;

    d = 1.5;
    i = int(d);
    cout << i << endl;
    i = d;
    cout << i << endl;

    d = 1.9;
    i = int(d);
    cout << i << endl;
    i = d;
    cout << i << endl;

    cout << "-----------" << endl;

    i = int(true);
    cout << i << endl;
    i = int(false);
    cout << i << endl;

    cout << "-----------" << endl;

    b = bool(5);
    cout << b << endl;
    b = bool(0);
    cout << b << endl;
    b = bool(-5);
    cout << b << endl;

    return 0;
}
