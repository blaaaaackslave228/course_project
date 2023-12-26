#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>  // Добавленный заголовочный файл
#include "UTF_8.h"
#include "UTF_16.h"
#include "WINDOWS1251.h"
#include "BIN.h"
#include "CODE.h"
#include "ASCII.h"
#include "ASCIIWIN1251.h"
#include "NUMBER.h"
using namespace std;

// Подключение функций для выделения надписи в рамку
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
    system("title SMT - конвертер символов");
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(1251);

    int choice;
    do {
        cout << "**************************************************************************************" << endl;
        drawTitle("Выберите вариант работы с программой: ");
        cout << "1 - Вывести кодировку символов в Windows-1251, форматы в UTF-8, UTF-16, двоичном коде." << endl;
        cout << "2 - Вывести кодировки латинских символов в ASCII." << endl;
        cout << "3 - Вывести кодировки русских символов в ASCII." << endl;
        cout << "4 - Получить латинский символ при вводе формата в ASCII." << endl;
        cout << "5 - Получить русский символ при вводе формата в ASCII WIN-1251." << endl;
        cout << "6 - Выход из программы." << endl;
        cout << endl;
        cout << "**************************************************************************************" << endl;
        cout << endl;
        cout << "Ваш вариант: ";
        cin >> choice;
        cout << endl;
        if (cin.fail() || choice < 1 || choice > 6) {
            cout << "Ошибка ввода! Пожалуйста, введите число от 1 до 6." << endl << endl;
            cin.clear(); // Очистка флага ошибки ввода
            cin.ignore(9999, '\n'); // Очистка буфера ввода
            continue; // Переход на следующую итерацию цикла
        }

        // Очищает символ новой строки из буфера
        cin.ignore();

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
            break;
        }
        case 2: {
            string symbol;
            cout << "Введите латинские символы: ";
            getline(cin, symbol);
            cout << endl;
            ascii(symbol);
            break;
        }
        case 3: {
            string symbol;
            cout << "Введите русские символы: ";
            getline(cin, symbol);
            cout << endl;
            ascii1(symbol);
            break;
        }
        case 4: {
            string code;
            cout << "Введите коды латинских символов: ";
            getline(cin, code);
            cout << endl;
            SymbolInfo(code);
            break;
        }
        case 5: {
            string code;
            cout << "Введите коды русских символов: ";
            getline(cin, code);
            cout << endl;
            Symbol_Info(code);
            break;
        }
        case 6: {
            break;
        }
        }
        break;  // Изменение в этой строке
    } while (choice != 6);

    return 0;
}
