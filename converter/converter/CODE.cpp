#include "CODE.h"
#include <bitset>
#include <iostream>
#include <sstream>
using namespace std;

bool isLatinChar(char ch) {
    return (ch >= 33 && ch <= 126);
}

//подключение функции, которая позволяет вводить символы разных форматов
int SymbolInfo(const string& input) {
    istringstream iss(input);
    string code;
    while (iss >> code) {
        int decimalCode;
        if (code.substr(0, 2) == "0x" || code.substr(0, 2) == "0X") {
            //шестнадцатеричная система счисления
            istringstream hexConverter(code.substr(2));
            hexConverter >> hex >> decimalCode;
        }
        else if (code.substr(0, 1) == "0") {
            //восьмеричная система счисления
            istringstream octConverter(code);
            octConverter >> oct >> decimalCode;
        }
        else {
            //десятичная система счисления
            istringstream decConverter(code);
            decConverter >> decimalCode;
        }
        char ch = static_cast<char>(decimalCode);
        if (!isLatinChar(ch)) {
            cout << "Ошибка: код символа не принадлежит латинской букве." << endl;
            continue;
        }
        //вывод найденного символа и других кодировок этого же символа
        cout << "Символ: " << ch << endl;
        cout << "ACSII код в десятичном формате: " << dec << decimalCode << endl;
        cout << "В восьмеричном формате: " << oct << decimalCode << endl;
        cout << "В шестнадцатеричном формате: " << hex << decimalCode << endl;
        cout << "В двоичном формате: " << bitset<8>(decimalCode) << endl;
        cout << endl;
    }
    return 0;
}