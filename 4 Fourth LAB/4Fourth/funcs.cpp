#include <iostream>
#include "funcs.h"

using namespace std;

int fibonacci(int number)
{
    if (number == 1)
        return 1;
    if (number == 2)
        return 1;
    return fibonacci(number-1) + fibonacci(number-2);
}

void mydiv(int arr[4]){
    int res;
    res = arr[3] - arr[2];
    for (int i = 2; i > 0; i--) {
        if (res > arr[i] - arr[i-1]){
            res = arr[i] - arr[i-1];
        }
    }
    cout << res;
}


void funcs(const int n)
{
    setlocale(LC_ALL, "Russian");
    int arr[4], temp, num, nBegin;
    if (1 <= n && n <= 3){                    // выбор вводимых данных
        cout << "Введите значения" << endl;
        for (int i = 0; i < 4; i++) {         // заполнение массива
            cin >> arr[i];
        }
        for (int i = 0; i < 3; i++) {         // сортировка массива
                for (int j = 0; j < 3 - i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                }
            }
        }
    }
    else if (n == 4) {
        cout << "Введите количество выводимых чисел" << endl;
        cin >> num;
        cout << "Введите индекс первого числа" << endl;
        cin >> nBegin;
    }
    switch (n) {
        case 1:                               // div
            mydiv(arr);
            break;
        case 2:                               // max
            cout << arr[3];
            break;
        case 3:                               // averege
            cout << (arr[0] + arr[1] + arr[2] + arr[3])/4.0;
            break;
        case 4:                               // fibonacci
            for (int i = nBegin; i < nBegin + num; i++){
                cout << fibonacci(i)<< ' ';
            }
            break;
        default:
            cout << "Неверно введён номер функции";
    }
}
