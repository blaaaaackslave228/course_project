#include<iostream>
#include <Windows.h>
#include <string>
#include "UTF_8.h"
using namespace std;

//����������� �������, ������� ��������� �������� ���� �������� � UTF-8 � UNICODE
int utf8(std::wstring symbol) {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    for (wchar_t ch : symbol) {
        //���������, �������� �� ������ ���������
        if ((ch >= L'!') && (ch <= L'~')) {
            wcout << L"UTF-8 ��� ������� " << ch << ": ";
            if (ch >= 0x00 && ch <= 0x7F) {
                wcout << hex << ((ch & 0x7F) | 0x00);
            }
            wcout << endl;
        }
        //�����, ���������, �������� �� ������ �������������
        else if ((ch >= L'�') && (ch <= L'�')) {
            wcout << L"UTF-8 ��� ������� " << ch << ": ";
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