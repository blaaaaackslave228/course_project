#include <iostream>
#include <string>
#include "NUMBER.h"
using namespace std;
//������� ��� �������� �������� �� ������ ������
bool isNumber(const string& str) {
    for (char const& c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}