#include <fstream>
#include <string>
#include <iostream>
#include "Newfile.h"

using namespace std;

void Check(const string& text1, const string& text2, const string& text3) {
    ifstream inFile(text1);
    ofstream outFile(text2);
    ifstream invalidFile(text3);

    if (!inFile.is_open()) {
        cout << "�� ������� ������� ���� " << text1 << endl;
        return;
    }

    if (!outFile.is_open()) {
        cout << "�� ������� �������� ���� " << text2 << endl;
        return;
    }

    if (!invalidFile.is_open()) {
        cout << "�� ������� ������� ���� " << text3 << " � ������� ������������ ���" << endl;
        return;
    }

    string word;
    string invalidWord;
    bool check;

    while (inFile >> word) {
        invalidFile.clear();
        invalidFile.seekg(0, ios::beg);

        check = true;
        while (invalidFile >> invalidWord) {
            if (word == invalidWord) {
                check = false;
                break;
            }
        }
        if (check) {
            outFile << word << " ";
        }
    }

    inFile.close();
    outFile.close();
    invalidFile.close();

    cout << "���� ������ �������� � ���������� ������������ ���" << endl;
}