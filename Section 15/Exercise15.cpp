// Zadanie 15 - Użytkownik wprowadza swoje zdanie. Następnie każde słowo rozdzielone spacjami trzeba zamienić na inne słowa, ktore użytkownik będzie chciał. Po wszystkim należy wypisać otrzymane słowo.
#include <iostream>
#include <sstream>
#include "../narzedzia.h"
using namespace std;

int main()
{
    string zdanie = wprowadzenie<string>("Wprowadz zdanie: ");

    stringstream strm(zdanie);
    strm.seekg(0);

    while(strm)
    {
        strm >> ws;

        // Ustawiwamy na dobrym miejscu
        strm.seekp(strm.tellg());

        string slowo;
        strm >> slowo;
        if(!strm)
            break;

        string zamiana = wprowadzenie<string>("Wprowadz na co mam zmienic \"" + slowo + "\":");
        if(zamiana.length() < slowo.length())
        {
            cout << "JEST";
            while (zamiana.length() != slowo.length())
            {
                zamiana += '\0';
            }
        }
        strm << zamiana;
    }

    cout << strm.str();
}