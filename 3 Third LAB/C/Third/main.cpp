#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while(a!=b){
        if (b > a){
            a += b;
            b = a - b;
            a -= b;
        }
        a -= b;
    }
    cout << a << endl;
    return 0;
}
