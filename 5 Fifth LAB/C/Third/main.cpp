#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int const n = 20;

int main()
{
    srand(time(NULL));
    int arr[n] = {};
    int count[21] = {};
    int max = 0;
    int ind = 0;

    for (int i = 0; i < n; i++){
        arr[i] = rand()%21;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    for (int i = 0; i < n; i++){
        for (int k = 0; k < n; k++){
            if (max < count[k]){
                max = count[k];
                ind = k;
            }
        }
        if (max != 0){
            cout << ind << " - " << max << " times" << endl;
            max = 0;
            count[ind] = 0;
        }
        else {
            return 0;
        }
    }

    return 0;
}
