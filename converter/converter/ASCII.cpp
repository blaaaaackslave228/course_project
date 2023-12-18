#include <iostream>
#include <string>
#include <Windows.h>
#include "ASCII.h"
#include <bitset>
using namespace std;

//подключение функции, которая выводит коды латинских символов в ASCII в различных форматов 
int ascii(string symbol)
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    for (char ch : symbol) {
        //проверяем, является ли символ латинским
        if (ch >= ' ' && ch <= '~') {
            if (ch != L' ' && ch != L'\n' && ch != L'\t') {
                //вывод форматов латинских символов в ASCII
                cout << "ACSII код латинского символа: " << ch << endl;
                cout << "В десятичном формате: " << std::dec << static_cast<int>(ch) << endl;
                cout << "В восьмеричном формате: " << std::oct << static_cast<int>(ch) << endl;
                cout << "В шестнадцатиричном формате: " << std::hex << static_cast<int>(ch) << endl;
                cout << "В двоичном формате: " << bitset<8>(ch) << endl;
                cout << endl;
            }
        }
        else {
            cout << "Введен неверный символ!" << endl;
        }
    }
    return 0;
}