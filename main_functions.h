#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// функция 1 string &s
void func(string &s){
    for (char &c : s) {
        if (c == ' ') {
            c = '_';
        }
    }

}

// функция 2 char *s
void func(char *s){
    if (s==nullptr) return;

    char *checkptr = s;
    char *copyptr = s;

    while (*checkptr != '\0'){
        if (!(*checkptr>='0' && *checkptr<='9')) {
            *copyptr = *checkptr;
            copyptr++;
        }

        checkptr++;
    }
    *copyptr = '\0';
}

// пространство имен 1
namespace version1 {
    // замена пробелов
    void func(string &s){
        for (char &c : s) {
            if (c == ' ') {
                c = '_';
            }
        }

    }
}

// пространство имен 2
namespace version2{
    // удаление цифр
    void func(char *s){
    if (s==nullptr) return;

    char *checkptr = s;
    char *copyptr = s;

    while (*checkptr != '\0'){
        if (!(*checkptr>='0' && *checkptr<='9')) {
            *copyptr = *checkptr;
            copyptr++;
        }

        checkptr++;
    }
    *copyptr = '\0';
}
}

// рекурсивная функция
string dectooct (long num){
// отрицательное число 
    if (num < 0) {
        return '-' + dectooct(-num);
    }

// базовый случай
    if (num < 8) {
        return to_string(num);
    }

// рекурсивный случай
    return dectooct(num/8) + to_string(num%8);

}

// поиск минимального значения
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