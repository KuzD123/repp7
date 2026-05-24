#include <iostream>
#include <ctime>
using namespace std;

int findMin(int* arr, int size, auto compare) {
    if (size <= 0 || arr == nullptr) {
        return 0; // защита от пустого массива
    }
    
    int minEl = arr[0]; // предполагаем, что первый элемент минимальный
    
    for (int i = 1; i < size; ++i) {
// используем лямбда-функцию для сравнения
        if (compare(arr[i], minEl)) {

            minEl = arr[i];
        }
    }
    
    return minEl;
}

int main(){

// создание рандомайзера
    srand(time(0));

// создание массива
    int s;
    cout << "размер массива? - ";
    cin >> s;
    int arr1[s];

    cout << "\nисходный массив: ";
    for (int i = 0; i < s; i++){
        arr1[i] = rand() % 100;
        cout << arr1[i] << ' ';
    }

// лямбда
    auto isLess = [](int a, int b) -> bool {
        return a < b;
    };

//
    int minval = findMin (arr1 , s, isLess);

    cout << "минимальный элемент массива: "<< minval;

return 0;

}