#include <iostream>
#include <string>
#include <Windows.h>
#include <bitset>
using namespace std;

int ascii1(const string& symbol)
{
    SetConsoleOutputCP(1251);
    for (unsigned char ch : symbol) {
        // Проверяем, является ли символ кириллическим (входит в CP1251)
        if ((ch >= 0x80 && ch <= 0xFF) || (ch >= 0xC0 && ch <= 0xDF)) {
            cout << "ASCII код кириллического символа: " << ch << endl;
            cout << "В десятичном формате: " << std::dec << static_cast<int>(ch) << endl;
            cout << "В восьмеричном формате: " << std::oct << static_cast<int>(ch) << endl;
            cout << "В шестнадцатиричном формате: " << std::hex << static_cast<int>(ch) << endl;
            cout << "В двоичном формате: " << bitset<8>(ch) << endl;
            cout << endl;
        }
        else if (ch != ' ' && ch != '\n' && ch != '\t') {
            cout << "Ошибка: Символ '" << ch << "' не входит в кодировку CP1251." << endl;
        }
    }
    return 0;
}