#include<iostream>
#include <Windows.h>
#include <string>
#include "WINDOWS1251.h"

using namespace std;

int windows(std::wstring symbol) {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    for (wchar_t ch : symbol) {
        if (ch != L' ' && ch != L'\n' && ch != L'\t') {
            wcout << L"Код в Windows-1251 символа " << ch << ": ";
            wcout << static_cast<int>(ch);
            wcout << endl;
        }
    }
    return 0;
}