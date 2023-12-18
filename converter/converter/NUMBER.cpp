#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include "NUMBER.h"
using namespace std;

// Функция, которая проверяет, является ли символ русской буквой
bool isRussianChar(unsigned char ch) {
    return (ch >= 192 && ch <= 255);
}

//подключение функции, которая позволит выводить символ по его введенному формату кода
int Symbol_Info(const string& input)
{
    istringstream iss(input);
    string code;
    while (iss >> code) {
        int decimalCode;
        if (code.substr(0, 2) == "0x" || code.substr(0, 2) == "0X") {
            // Шестнадцатеричная система счисления
            istringstream hexConverter(code.substr(2));
            hexConverter >> hex >> decimalCode;
        }
        else if (code.substr(0, 1) == "0") {
            // Восьмеричная система счисления
            istringstream octConverter(code);
            octConverter >> oct >> decimalCode;
        }
        else {
            // Десятичная система счисления
            istringstream decConverter(code);
            decConverter >> decimalCode;
        }
        unsigned char ch = static_cast<char>(decimalCode);
        if (!isRussianChar(ch)) {
            cout << "Ошибка: код символа не принадлежит русской букве." << endl;
            continue;
        }
        cout << "Символ: " << ch << endl;
        cout << "ACSII код в десятичном формате: " << dec << decimalCode << endl;
        cout << "В восьмеричном формате: " << oct << decimalCode << endl;
        cout << "В шестнадцатеричном формате: " << hex << decimalCode << endl;
        cout << "В двоичном формате: " << bitset<8>(decimalCode) << endl;
        cout << endl;
    }
    return 0;
}
