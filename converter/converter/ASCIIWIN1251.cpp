#include <iostream>
#include <string>
#include <Windows.h>
#include <bitset>
using namespace std;

int ascii1(const string& symbol)
{
    SetConsoleOutputCP(1251);
    for (unsigned char ch : symbol) {
        // ���������, �������� �� ������ ������������� (������ � CP1251)
        if ((ch >= 0x80 && ch <= 0xFF) || (ch >= 0xC0 && ch <= 0xDF)) {
            cout << "ASCII ��� �������������� �������: " << ch << endl;
            cout << "� ���������� �������: " << std::dec << static_cast<int>(ch) << endl;
            cout << "� ������������ �������: " << std::oct << static_cast<int>(ch) << endl;
            cout << "� ����������������� �������: " << std::hex << static_cast<int>(ch) << endl;
            cout << "� �������� �������: " << bitset<8>(ch) << endl;
            cout << endl;
        }
        else if (ch != ' ' && ch != '\n' && ch != '\t') {
            cout << "������: ������ '" << ch << "' �� ������ � ��������� CP1251." << endl;
        }
    }
    return 0;
}