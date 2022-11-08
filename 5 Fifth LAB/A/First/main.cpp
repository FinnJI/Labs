#include <iostream>

using namespace std;

int main()
{
    char x;
    double y;
    char c;

    char *pi;
    double *pf;
    char *pc;

    cout << "Enter value (int, double, char): ";
    cin >> x >> y >> c;

    pi = &x;
    pf = &y;
    pc = &c;

    *pi += *pi;
    *pf *= 2;
    *pc += 5;

    cout << "x = " << *pi << " (" << (const void *) pi << ")"<< endl;
    cout << "y = " << *pf << " (" << pf << ")"<< endl;
    cout << "c = " << pc << " (" <<  (const void *) pc << ")"<< endl;

    cout << "&pi =" << "(" << &pi << ")"<< endl;
    cout << "&pf =" << "(" << &pf << ")"<< endl;
    cout << "&pc =" << "(" << &pc << ")"<< endl;

    return 0;
}
