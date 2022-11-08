#include <iostream>
#include "funcs.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Выберите функцию: max, div или average " << endl;
    cout << "1. div" << endl;
    cout << "2. max" << endl;
    cout << "3. average" << endl;
    cout << "4. fibonacci" << endl;
    cin >> n;
    funcs(n);

    return 0;
}
