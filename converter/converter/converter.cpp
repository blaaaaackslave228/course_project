#include <iostream>
#include <Windows.h>
#include <string>
#include "UTF_8.h"
#include "UTF_16.h"
#include "DEC.h"
#include "BIN.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    do
    {
        cout << "Choose an operation and enter the corresponding number: " << endl;
        cout << "1 - Display binary, UTF-16, and Windows-1251 codes for a character" << endl;
        cout << "2 - Enter a description for operation 2" << endl;
        cout << "3 - Exit the program" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1: {
            wstring symbol;
            wcout << L"Enter a character: ";
            getline(wcin, symbol);
            utf8(symbol);
            bin(symbol);
            utf16(symbol);
            dec(symbol);
            choice = 3; break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        }

    } while (choice != 3);
    return 0;
}
