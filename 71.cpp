// Кузьмина Дарья Ивановна
// сырой код задания 1 с полным набором функций
#include "check_functions.h" // подключение функций проверки
using namespace std;

// прототипы
    // перегруженные ф-ии для string и char (1)
void func(string &s);
void func(char *s);

int main() {
    // ввод строки с контролем ввода
    string text1 = enterStr("\nвведите 1-ую исходную строку: ");

    cout << "исходная строка (string)): " << text1 <<'\n';
    func(text1); // обращение к функции замены пробелов
    cout << "после замены пробелов: " << text1 << '\n';
    
    // обозначение символьного массива 
    char text2[100];
    enterarrChar("Введите вторую строку (char*): ", text2, 100);

    cout << "\nисходная строка (char*)): " << text2 <<'\n';
    func(text2);
    cout << "после удаления цифр: " << text2 << '\n';
}

void func(string &s){
    for (char &c : s) {
        if (c == ' ') {
            c = '_';
        }
    }

}

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

