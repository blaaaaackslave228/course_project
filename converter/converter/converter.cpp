#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>  // ����������� ������������ ����
#include "UTF_8.h"
#include "UTF_16.h"
#include "WINDOWS1251.h"
#include "BIN.h"
#include "CODE.h"
#include "ASCII.h"
#include "ASCIIWIN1251.h"
#include "NUMBER.h"
using namespace std;

// ����������� ������� ��� ��������� ������� � �����
void drawLine(char ch, int length) {
    for (int i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
}

void drawTitle(string title) {
    const int titleWidth = title.length() + 4;
    drawLine('-', titleWidth);
    cout << "| " << title << " |" << endl;
    drawLine('-', titleWidth);
}

int main() {
    HWND consoleWindow = GetConsoleWindow();
    int new_width = 750;
    int new_height = 1000;
    RECT rect;
    GetWindowRect(consoleWindow, &rect);
    MoveWindow(consoleWindow, rect.left, rect.top, new_width, new_height, TRUE);
    system("title SMT - ��������� ��������");
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);

    int choice;
    do {
        cout << "**************************************************************************************" << endl;
        drawTitle("�������� ������� ������ � ����������: ");
        cout << "1 - ������� ��������� �������� � Windows-1251, ������� � UTF-8, UTF-16, �������� ����." << endl;
        cout << "2 - ������� ��������� ��������� �������� � ASCII." << endl;
        cout << "3 - ������� ��������� ������� �������� � ASCII." << endl;
        cout << "4 - �������� ��������� ������ ��� ����� ������� � ASCII." << endl;
        cout << "5 - �������� ������� ������ ��� ����� ������� � ASCII WIN-1251." << endl;
        cout << "6 - ����� �� ���������." << endl;
        cout << endl;
        cout << "**************************************************************************************" << endl;
        cout << endl;
        cout << "��� �������: ";
        cin >> choice;
        cout << endl;
        if (cin.fail() || choice < 1 || choice > 6) {
            cout << "������ �����! ����������, ������� ����� �� 1 �� 6." << endl << endl;
            cin.clear(); // ������� ����� ������ �����
            cin.ignore(9999, '\n'); // ������� ������ �����
            continue; // ������� �� ��������� �������� �����
        }

        // ������� ������ ����� ������ �� ������
        cin.ignore();

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
            break;
        }
        case 2: {
            string symbol;
            cout << "������� ��������� �������: ";
            getline(cin, symbol);
            cout << endl;
            ascii(symbol);
            break;
        }
        case 3: {
            string symbol;
            cout << "������� ������� �������: ";
            getline(cin, symbol);
            cout << endl;
            ascii1(symbol);
            break;
        }
        case 4: {
            string code;
            cout << "������� ���� ��������� ��������: ";
            getline(cin, code);
            cout << endl;
            SymbolInfo(code);
            break;
        }
        case 5: {
            string code;
            cout << "������� ���� ������� ��������: ";
            getline(cin, code);
            cout << endl;
            Symbol_Info(code);
            break;
        }
        case 6: {
            break;
        }
        }
        break;  // ��������� � ���� ������
    } while (choice != 6);

    return 0;
}
