#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double tmp = 2, s = 1;
    int i, N;
    cin >> N;
    for (i = 1; i <= N; i++) {
        s += 1/tmp;
        tmp *= 2;
    }
    cout << "Sum: " << s;
    return 0;
}
