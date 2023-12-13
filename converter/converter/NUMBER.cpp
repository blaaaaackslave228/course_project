#include <iostream>
#include <string>
#include "NUMBER.h"
using namespace std;
//функция для проверки является ли строка числом
bool isNumber(const string& str) {
    for (char const& c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}