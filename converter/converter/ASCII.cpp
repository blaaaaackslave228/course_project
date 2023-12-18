#include <iostream>
#include <string>
#include <Windows.h>
#include "ASCII.h"
#include <bitset>
using namespace std;

//����������� �������, ������� ������� ���� ��������� �������� � ASCII � ��������� �������� 
int ascii(string symbol)
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    for (char ch : symbol) {
        //���������, �������� �� ������ ���������
        if (ch >= ' ' && ch <= '~') {
            if (ch != L' ' && ch != L'\n' && ch != L'\t') {
                //����� �������� ��������� �������� � ASCII
                cout << "ACSII ��� ���������� �������: " << ch << endl;
                cout << "� ���������� �������: " << std::dec << static_cast<int>(ch) << endl;
                cout << "� ������������ �������: " << std::oct << static_cast<int>(ch) << endl;
                cout << "� ����������������� �������: " << std::hex << static_cast<int>(ch) << endl;
                cout << "� �������� �������: " << bitset<8>(ch) << endl;
                cout << endl;
            }
        }
        else {
            cout << "������ �������� ������!" << endl;
        }
    }
    return 0;
}