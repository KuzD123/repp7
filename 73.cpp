#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
int grThan( T* array, int size, T value);

int main(){
    srand(time(0));

//int массив   

    int num1;
    cout<< "\nразмер массива int? - ";
    cin >> num1;
    int intarr[num1];
    cout << "\nмассив int: ";

    for (int i = 0; i < num1; i++){
        intarr[i] = rand() % 10;
        cout << intarr[i]<< ' ';
    }

    int val1;
    cout << "\nвведите элемент: ";
    cin >> val1;

    int resint = grThan(intarr, num1, val1);
    cout << "количество элементов больше "<< val1 << " : " << resint << '\n';

// double массив

    int num2;
    cout<< "\nразмер массива double? - ";
    cin >> num2;
    int doublearr[num2];
    cout << "\nмассив double: ";

    for (int i = 0; i < num2; i++){
        doublearr[i] = rand() % 10;
        cout << doublearr[i] << ' ';
    }

    int val2;
    cout << "\nвведите элемент: ";
    cin >> val2;

    int resdouble = grThan(doublearr, num2, val2);
    cout << "количество элементов больше "<< val2 << " : " << resdouble << '\n';
}



template<typename T>
int grThan(T*array, int size, T value) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > value) {
            count++;
        }
    }
    return count;
}