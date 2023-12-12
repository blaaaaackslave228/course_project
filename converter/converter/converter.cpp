#include <iostream>
#include <Windows.h>
#include <string>
#include "UTF_8.h"
#include "UTF_16.h"
#include "WINDOWS1251.h"
#include "BIN.h"

using namespace std;

int main() {
    system("title ��������� ��������");
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "�������� ������� ������ � ����������: " << endl;
        cout << "1 - ������� ��������� �������� � Windows-1251, ������� � UTF-8, UTF-16, �������� ����" << endl;
        cout << "2 - �������� ������ ��� ����� ��������� ��� �������" << endl;
        cout << "3 - ����� �� ���������" << endl;
        cin >> choice;
        cin.ignore(); // ��������� ��� ����������� ���������� ������
        switch (choice) {
        case 1: {
            wstring symbol;
            wcout << L"������� �������: ";
            getline(wcin, symbol);
            wcout << endl;
                utf8(symbol);
                wcout << endl;
                bin(symbol);
                wcout << endl;
                utf16(symbol);
                wcout << endl;
                windows(symbol);
                wcout << endl;
            break;
        }
        case 2: {
            // ���������� �������� 2 �����
            break;
        }
        case 3: {
            break;
        }
        }
    } while (choice != 3);
    return 0;
}