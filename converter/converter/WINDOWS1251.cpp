#include<iostream>
#include <Windows.h>
#include <string>
#include "WINDOWS1251.h"
using namespace std;

//подключение функции, которая позволяет найти десятичный формат символов
int windows(wstring symbol) {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    for (wchar_t ch : symbol) {
        if (ch != L' ' && ch != L'\n' && ch != L'\t') {
            if (ch >= L'!' && ch <= L'~') {
                wcout << L"Десятичный код в Windows-1251 символа " << ch << ": ";
                wcout << std::dec << static_cast<int>(ch);
                wcout << endl;
            }
            else if ((ch >= L'а' && ch <= L'я') || (ch >= L'А' && ch <= L'Я')) {
                wcout << L"Код в десятичном формате символа " << ch << ": ";
                wcout << std::dec << static_cast<int>(ch);
                wcout << endl;
            }
        }
    }
    return 0;
}
