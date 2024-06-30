#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Newfile.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Check("text.txt", "text2.txt", "text3.txt");

    return 0;
}