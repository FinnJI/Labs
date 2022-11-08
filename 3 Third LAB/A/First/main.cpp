#include <iostream>

using namespace std;

int main()
{
    int s = 0;
    int ch;
    cin >> ch;
    while (ch > 1){
        if (ch % 2 != 0 ){
            cout << "Not a power of two" << endl;
            return 0;
        }
        ch /= 2;
        s++;
    }
    cout << s << endl;
    return 0;
}
