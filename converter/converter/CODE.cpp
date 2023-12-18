#include "CODE.h"
#include <bitset>
#include <iostream>
#include <sstream>
using namespace std;

bool isLatinChar(char ch) {
    return (ch >= 33 && ch <= 126);
}

//����������� �������, ������� ��������� ������� ������� ������ ��������
int SymbolInfo(const string& input) {
    istringstream iss(input);
    string code;
    while (iss >> code) {
        int decimalCode;
        if (code.substr(0, 2) == "0x" || code.substr(0, 2) == "0X") {
            //����������������� ������� ���������
            istringstream hexConverter(code.substr(2));
            hexConverter >> hex >> decimalCode;
        }
        else if (code.substr(0, 1) == "0") {
            //������������ ������� ���������
            istringstream octConverter(code);
            octConverter >> oct >> decimalCode;
        }
        else {
            //���������� ������� ���������
            istringstream decConverter(code);
            decConverter >> decimalCode;
        }
        char ch = static_cast<char>(decimalCode);
        if (!isLatinChar(ch)) {
            cout << "������: ��� ������� �� ����������� ��������� �����." << endl;
            continue;
        }
        //����� ���������� ������� � ������ ��������� ����� �� �������
        cout << "������: " << ch << endl;
        cout << "ACSII ��� � ���������� �������: " << dec << decimalCode << endl;
        cout << "� ������������ �������: " << oct << decimalCode << endl;
        cout << "� ����������������� �������: " << hex << decimalCode << endl;
        cout << "� �������� �������: " << bitset<8>(decimalCode) << endl;
        cout << endl;
    }
    return 0;
}