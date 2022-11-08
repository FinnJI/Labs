#include <iostream>

using namespace std;

int main()
{
    int n = 3;
    bool f = 1;
    int last = 2;
    int arr[n]={};

    if (n<=2){
        for (int i = 1; i <= n; i++){
            arr[i-1]=i;
            cout << i << " ";
        }
        return 0;
    }
    arr[0] = 1;
    arr[1] = 2;

    for (int i = 2; i-1 < n; i++){
        for (int j=last+1;; j++){
            for (int d = 2; d < j; d++){
                if (j%d == 0){
                    f = 0;
                    break;
                }
            }
            if (f){
                last = j;
                break;
            }
        }
        arr[i] = last;
    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
