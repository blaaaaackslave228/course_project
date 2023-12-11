#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int utf8(wstring symbol) {
    for (wchar_t ch : symbol) {
        if ((ch >= L'!') && (ch <= L'~')) {
            wcout << L"UTF-8 код символа " << ch << ": ";
            if (ch >= 0x00 && ch <= 0x7F) {
                wcout << hex << ((ch & 0x7F) | 0x00);
            }
            wcout << endl;
        }
        else if ((ch >= L'А') && (ch <= L'я')) {
            wcout << L"UTF-8 код символа " << ch << ": ";
            if (ch >= 0x00 && ch <= 0x7F) {
                wcout << hex << ((ch & 0x7F) | 0x00);
            }
            else if (ch >= 0x80 && ch <= 0x7FF) {
                wcout << hex << ((ch >> 6) | 0xC0) << ((ch & 0x3F) | 0x80);
            }
            else if (ch >= 0x800 && ch <= 0xFFFF) {
                wcout << hex << ((ch >> 12) | 0xE0) << ' ' << (((ch >> 6) & 0x3F) | 0x80) << ' ' << ((ch & 0x3F) | 0x80);
            }
            if (ch >= 0x10000 && ch <= 0x1FFFF) {
                wcout << hex << ((ch >> 18) | 0xF0) << ' '
                    << (((ch >> 12) & 0x3F) | 0x80) << ' '
                    << (((ch >> 6) & 0x3F) | 0x80) << ' '
                    << ((ch & 0x3F) | 0x80);
            }
            wcout << endl;
        }
    }
    return 0;
}

int bin(wstring symbol) {
    for (wchar_t ch : symbol) {
        char tmp[33];
        _itoa_s(static_cast<int>(ch), tmp, 33, 2);
        wcout << L"Код символа в BIN: " << tmp;
        wcout << endl;
    }
    return 0;
}

int utf16(wstring symbol) {
    for (wchar_t ch : symbol) {
        wcout << L"UTF-16 код символа " << ch << ": ";
        if (ch >= 0x10000) {
            wcout << hex << ((ch - 0x10000) / 0x400 + 0xD800) << ' ' << (((ch - 0x10000) % 0x400) + 0xDC00);
        }
        else {
            wcout << hex << static_cast<int>(ch);
        }
        wcout << endl;
    }
    return 0;
}

int dec(wstring symbol) {
    for (wchar_t ch : symbol) {
        wcout << L"DEC код символа " << ch << ": ";
        wcout << static_cast<int>(ch);
        wcout << endl;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    wstring symbol;
    wcout << L"Введите символы: ";
    getline(wcin, symbol);
    utf8(symbol);
    bin(symbol);
    utf16(symbol);
    dec(symbol);
    return 0;
}
