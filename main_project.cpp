#include <map>
#include <algorithm>
#include "check_functions.h"
#include "main_functions.h"
using namespace std;


// прототипы
    // перегруженные ф-ии для string и char (1)
void func(string &s);
void func(char *s);
    // количество элементов массива больше определенного знчения (3)
template<typename T>
int grThan( T* array, int size, T value);

// задача 1
void problem1(){
    string text1 = enterStr("\nвведите 1-ую исходную строку: ");

    cout << "исходная строка (string)): " << text1 <<'\n';
    func(text1);
    cout << "после замены пробелов: " << text1 << '\n';
    
    char text2[100];
    enterarrChar("Введите вторую строку (char*): ", text2, 100);

    cout << "\nисходная строка (char*)): " << text2 <<'\n';
    func(text2);
    cout << "после удаления цифр: " << text2 << '\n';

}

// задача 2
void problem2(){

    string text1 = enterStr("\nвведите 1-ую исходную строку: ");
    char text2[100];
    enterarrChar("Введите вторую строку (char*): ", text2, 100);
    
    cout << "исходная строка (string)): " << text1 <<'\n';
    version1:: func(text1);
    cout << "после замены пробелов: " << text1 << '\n';
    
    cout << "\nисходная строка (char*)): " << text2 <<'\n';
    version2::func(text2);
    cout << "после удаления цифр: " << text2 << '\n';

}

// задача 3
void problem3(){

    srand(time(0));

//int массив   
    int num = enterInt("\nвведите размер массивов: ", 1, 100); 
    int intarr[num];

    cout << "\nмассив int: ";
    for (int i = 0; i < num; i++){
        intarr[i] = rand() % 10;
        cout << intarr[i]<< ' ';
    }

    int val1 = enterInt("введите элемент: ", 1, 100);

    int resint = grThan(intarr, num, val1);
    cout << "количество элементов больше "<< val1 << " : " << resint << '\n';

// double массив

    double doublearr[num];
    cout << "\nмассив double: ";

    for (int i = 0; i < num; i++){
        doublearr[i] = (rand() % 200 - 100) / 10.0;
        cout << doublearr[i] << ' ';
    }

    double val2 = enterInt("введите элемент: ", 1, 100);

    int resdouble = grThan(doublearr, num, (double)val2);
    cout << "количество элементов больше "<< val2 << " : " << resdouble << '\n';
}

// задача 4
void problem4(){ 
    
    long n = enterInt("введите десятичное число: ", 1, 1000);
    string res = dectooct(n);
    cout <<"число "<< n <<" в восмиричной системе: "<< res;
}

// задача 5
void problem5(){ 
        // создание рандомайзера
    srand(time(0));

        // создание массива
    int s = enterInt("\nвведите размер массива: ", 1, 1000);
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

    int minval = findMin (arr1 , s, isLess);
    cout << "минимальный элемент массива: "<< minval;
}

//создание меню
struct manuItem {
    string title;
    void (*action)();
};

int main() {
    map<int, manuItem> menu ={
        {1,{"problem1 ", problem1}},
        {2,{"problem2 ", problem2}},
        {3,{"problem3 ", problem3}},
        {4,{"problem4 ", problem4}},
        {5,{"problem5 ", problem5}},
    } ;

    int choice = 0;

    while (true) {
        cout << "\nМеню:\n";

        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << '\n';
        }
        
        cout << "0. Выход\n";

        choice = enterInt("введите номер пункта: ", 0,5);

        if (choice == 0) {
            cout << " -- \n";
            break;
        }

        if (menu.find(choice) != menu.end()){
            menu[choice].action();
        } else {
            cout << "некорректнай ввод";
        }

    }
    return 0;
}


// реализация шаблонной функции
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