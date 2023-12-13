#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <bitset>
#include "UTF_8.h"
#include "UTF_16.h"
#include "WINDOWS1251.h"
#include "BIN.h"
#include "CODE.h"
#include "ASCII.h"
#include "ASCIIWIN1251.h"

using namespace std;

int main() 
{
    HWND consoleWindow = GetConsoleWindow();
    int new_width = 750;
    int new_height = 500;
    RECT rect;
    GetWindowRect(consoleWindow, &rect);
    MoveWindow(consoleWindow, rect.left, rect.top, new_width, new_height, TRUE);
    system("title Конвертер символов");
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "Выберите вариант работы с программой: " << endl;
        cout << "1 - Вывести кодировку символов в Windows-1251, форматы в UTF-8, UTF-16, двоичном коде." << endl;
        cout << "2 - Вывести кодировки латинских символов в ASCII." << endl;
        cout << "3 - Вывести кодировки русских символов в ASCII." << endl;
        cout << "4 - Получить латинский или русский символ при вводе формата в ASCII." << endl;
        cout << "5 - Получить латинский или русский символ при вводе формата в UNICODE." << endl;
        cout << "6 - Выход из программы." << endl;
        cin >> choice;
        cin.ignore();
        cout << endl;
        switch (choice) {
        case 1: {
            wstring symbol;
            wcout << L"Введите символы: ";
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
            
            break;
        }
        case 3: {
            
            break;
        }
        case 4: {
            
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            break;
        }
        default: {
            cout << "Вы неправильно ввели номер операции! Пожалуйста, введите номер правильно." << endl;
            break;
        }
        }
        cout << endl;
    } while (choice != 6);
    return 0;
}