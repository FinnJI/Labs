#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    srand(time(NULL));
    int arr[30] = {};
    int dif = 0, maxdif = 0, maxlen = 0;
    int len = 1;


    for (int i = 0; i < 30; i++){
        arr[i] = rand()%100;
        cout << arr[i] << " ";
    }

    for (int i = 1; i < 30; i++){
        if (arr[i] > arr[i-1]){
            dif += (arr[i] - arr[i-1]);
            len++;
        }
        else{
            if (maxdif < dif){
                maxdif = dif;
                dif = 0;
                maxlen = len;
                len = 1;

            }
            else{
                dif = 0;
                len = 1;
            }
        }
    }

    if (maxdif < dif){
        maxdif = dif;
        maxlen = len;
    }
    cout << "\nSize: " << maxdif << " Lenght: " << maxlen;
    return 0;
}
