#include<iostream>
#include <Windows.h>
#include <string>
#include "DEC.h"

using namespace std;

int dec(wstring symbol) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    for (wchar_t ch : symbol) {
        if (ch != L' ' && ch != L'\n' && ch != L'\t') {
            wcout << L"Code in Windows-1251 for the character " << ch << ": ";
            wcout << static_cast<int>(ch);
            wcout << endl;
        }
    }
    return 0;
}