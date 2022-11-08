#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    unsigned char uc = -1;
    char c = uc;
    cout << c << endl;
    cout << uc << endl;

    unsigned short int ui = -1;
    short int i = int(ui/2);
    cout << i << endl;
    cout << ui << endl;

    uc = 250;
    uc = uc + 10;

    c = 100;
    c = c + 30;

    cout << c << endl;
    cout << uc << endl;

    i = 32740 + 30;
    cout << i << endl;
    return 0;
}
