#include<iostream>
#include <Windows.h>
#include <string>
#include "CODE.h"
#include "NUMBER.h"
#include <cctype>
using namespace std;

// Функция для преобразования строки с кодом символа в символ
char code_symbols(const string& code) {
    int num;
    string str = string(1, code[0]) + string(1, code[1]);

    // Если код начинается с '0x' или '0X', то это шестнадцатеричный код
    if (str == "0x" || str == "0X") {
        if (isNumber(code.substr(2))) {
            num = stoi(code.substr(2), nullptr, 16);
        }
        else {
            cout << "Ошибка: недопустимый код символа." << endl;
            return -1;
        }
    }
    // Если код начинается с '0b' или '0B', то это двоичный код
    else if (str == "0b" || str == "0B") {
        if (isNumber(code.substr(2))) {
            num = stoi(code.substr(2), nullptr, 2);
        }
        else {
            cout << "Ошибка: недопустимый код символа." << endl;
            return -1;
        }
    }
    // Иначе предполагаем, что это десятичный код
    else {
        if (isNumber(code)) {
            num = stoi(code);
        }
        else {
            cout << "Ошибка: недопустимый код символа." << endl;
            return -1;
        }
    }

    return static_cast<char>(num);
}