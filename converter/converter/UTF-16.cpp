#include<iostream>
#include <Windows.h>
#include <string>
#include "UTF_16.h"

using namespace std;

int utf16(std::wstring symbol) {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    for (wchar_t ch : symbol) {
        if (ch != L' ' && ch != L'\n' && ch != L'\t')
        {
            wcout << L"UTF-16 код символа " << ch << ": ";
            if (ch >= 0x10000) {
                wcout << hex << ((ch - 0x10000) / 0x400 + 0xD800) << ' ' << (((ch - 0x10000) % 0x400) + 0xDC00);
            }
            else {
                wcout << hex << static_cast<int>(ch);
            }
            wcout << endl;
        }
    }
    return 0;
}