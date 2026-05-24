#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <ctime>
#include <map>
#include <algorithm>

using namespace std;

// функция проверки корректности ввода числа

bool userinputprint (string input, int minValue, int maxValue){
    if (input.empty()) return false; //проверка пустой строки
    try {
        // переменная хранения позиции до которой считано число
        size_t pos;
        // преобразование строки в int
        int res = stoi(input, &pos);

        // обработана ли строка числом (pos < input.length() если есть лишние символы)
        return(pos == input.length() && (res >= minValue && res <= maxValue));
    } //ловим все исключения возникающие при stoi
    catch (...) {return false;}
}


// функция ввода числа с повторением запроса до корректного ввода

int enterInt(string label, int minValue = numeric_limits<int>::min(), int maxValue = numeric_limits<int>::max()){
    string raw_input;
    cout << '\n' << label;
    getline(cin,raw_input); // считывание строки полностью

    while (! userinputprint(raw_input, minValue, maxValue) ){
        cout << label;
        getline(cin,raw_input);
    }
    return stoi(raw_input); // конвертация строки в int
}

// функция проверки корректности ввода непустой строк типа string

bool userinputstr(string input){
    input.erase(remove_if(input.begin(), input.end(), ::isspace),input.end());
    return !input.empty();
}

// функция ввода строки с повторением запроса до корректного ввода

string enterStr(string label){
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    while (! userinputstr(raw_input)){
        cout << label;
        getline(cin, raw_input);
    }
    return raw_input;
}

// функция проврки корректности ввода непустой строки типа char[]

bool userinpurarrChar(const char str[]){
    const char *p = str;

    while (*p != '\0')
        if (*p++ != ' ') return true;
    return false;
}

// функция ввода строки с повторением запроса до корректного ввода

void enterarrChar(const char label[], char output[], size_t size){
    cout << label;
    cin.getline(output, size);

    while (! userinpurarrChar(output)){
        cout << label;
        cin.getline(output, size);
    }
}
