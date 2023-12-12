#include<iostream>
#include <Windows.h>
#include <string>
#include "BIN.h"

using namespace std;

int bin(std::wstring symbol) {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    for (wchar_t ch : symbol) {
        if (ch != L' ' && ch != L'\n' && ch != L'\t')
        {
            char tmp[33];
            _itoa_s(static_cast<int>(ch), tmp, 33, 2);
            wcout << L"Двоичный код символа " << ch << ": " << tmp;
            wcout << endl;
        }
    }
    return 0;
}