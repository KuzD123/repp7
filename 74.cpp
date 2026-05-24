#include <iostream>
using namespace std;

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

int main(){
    long n;
    cout <<"введите десятичное число: ";
    cin >> n;
    string res = dectooct(n);
    cout <<"число "<< n <<" в восмиричной системе: "<< res;
    
    return 0;


}