#include <iostream>
#include <Windows.h>
#include <string>
#include "UTF_8.h"
#include "UTF_16.h"
#include "WINDOWS1251.h"
#include "BIN.h"

using namespace std;

int main() {
    system("title Конвертер символов");
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "Выберите вариант работы с программой: " << endl;
        cout << "1 - Вывести кодировку символов в Windows-1251, форматы в UTF-8, UTF-16, двоичном коде" << endl;
        cout << "2 - Получить символ при вводе кодировки или формата" << endl;
        cout << "3 - Выход из программы" << endl;
        cin >> choice;
        cin.ignore(); // Добавлено для корректного считывания строки
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
            // Реализуйте операцию 2 здесь
            break;
        }
        case 3: {
            break;
        }
        }
    } while (choice != 3);
    return 0;
}