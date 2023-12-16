#include<iostream>
#include <Windows.h>
#include <string>
#include "WINDOWS1251.h"
using namespace std;

//����������� �������, ������� ��������� ����� ���������� ������ ��������
int windows(wstring symbol) {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    for (wchar_t ch : symbol) {
        if (ch != L' ' && ch != L'\n' && ch != L'\t') {
            if (ch >= L'!' && ch <= L'~') {
                wcout << L"���������� ��� � Windows-1251 ������� " << ch << ": ";
                wcout << std::dec << static_cast<int>(ch);
                wcout << endl;
            }
            else if ((ch >= L'�' && ch <= L'�') || (ch >= L'�' && ch <= L'�')) {
                wcout << L"��� � ���������� ������� ������� " << ch << ": ";
                wcout << std::dec << static_cast<int>(ch);
                wcout << endl;
            }
        }
    }
    return 0;
}
