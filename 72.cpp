#include <iostream>
#include <string>
#include <cstring>
using namespace std;



namespace version1 {
    void func(string &s){
        for (char &c : s) {
            if (c == ' ') {
                c = '_';
            }
        }

    }
}

namespace version2{
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


int main() {
    string text1 = "i love programming";
    char text2[] = "1i lov3e pr0ogr4amm11ing";
    
    cout << "исходная строка (string)): " << text1 <<'\n';
    version1:: func(text1);
    cout << "после замены пробелов: " << text1 << '\n';
    
    
    cout << "\nисходная строка (char*)): " << text2 <<'\n';
    version2::func(text2);
    cout << "после удаления цифр: " << text2 << '\n';

    return 0;
}