// Zadanie 7 - Sprawdzasz błędów. Pozwól użytkownikowi samemu stworzyć wyrażenie regularne. Następnie niech program sprawdzi czy jest to
// dobre wyrażenie. Niech wypisze informacje na ekranie.
#include <regex>
#include <iostream>
#include "../narzedzia.h"
using namespace std;

int main()
{
    string str = wprowadzenie<string>("Wprowadz wyrazenie regularne w jezyku ECMA Script: ");

    try {
        regex reg(str);

        cout << "Dobry kod!" << endl;
    }
    catch (const regex_error &e)
    {
        cout << "Zly kod!" << endl;
        cerr << e.what() << endl;
    }
}