#include <iostream>

using namespace std;

int main()
{
    unsigned long int ui;
    long int i;
    float f;
    i = -1;
    ui = i;
    f = ui;
    cout << f << endl;
    f = f + 1; //10000;
    cout << f << endl;

    double d;
    d = ui;
    cout << d << endl;
    d = d + 1;
    cout << d << endl;

    f = 1.0;
    float delta = 0.00000001;
    cout << (delta + f == f) << endl;

    f = 10.0;
          delta = 0.0000001;
    cout << (delta + f == f) << endl;


    return 0;
}
