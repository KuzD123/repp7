#include <iostream>
#include <string>
#include <cstring>
using namespace std;


void func(string &s);
void func(char *s);




int main() {
    string text1 = "i love programming";
    cout << "исходная строка (string)): " << text1 <<'\n';
    
    func(text1);
    
    cout << "после замены пробелов: " << text1 << '\n';
    
    char text2[] = "1i lov3e pr0ogr4amm11ing";
    cout << "\nисходная строка (char*)): " << text2 <<'\n';

    func(text2);

    cout << "после удаления цифр: " << text2 << '\n';

    return 0;
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

