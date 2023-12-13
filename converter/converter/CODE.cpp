#include<iostream>
#include <Windows.h>
#include <string>
#include "CODE.h"
#include "NUMBER.h"
#include <cctype>
using namespace std;

// ������� ��� �������������� ������ � ����� ������� � ������
char code_symbols(const string& code) {
    int num;
    string str = string(1, code[0]) + string(1, code[1]);

    // ���� ��� ���������� � '0x' ��� '0X', �� ��� ����������������� ���
    if (str == "0x" || str == "0X") {
        if (isNumber(code.substr(2))) {
            num = stoi(code.substr(2), nullptr, 16);
        }
        else {
            cout << "������: ������������ ��� �������." << endl;
            return -1;
        }
    }
    // ���� ��� ���������� � '0b' ��� '0B', �� ��� �������� ���
    else if (str == "0b" || str == "0B") {
        if (isNumber(code.substr(2))) {
            num = stoi(code.substr(2), nullptr, 2);
        }
        else {
            cout << "������: ������������ ��� �������." << endl;
            return -1;
        }
    }
    // ����� ������������, ��� ��� ���������� ���
    else {
        if (isNumber(code)) {
            num = stoi(code);
        }
        else {
            cout << "������: ������������ ��� �������." << endl;
            return -1;
        }
    }

    return static_cast<char>(num);
}