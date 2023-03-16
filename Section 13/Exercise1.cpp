// Zadanie 1 - Formatowanie imion. Pozwól użytkownikowi wprowadzac imiona i nazwiska, które następnie będą zawsze formatowane do 
// podanego wzorca: Adam Wojnarowski i wpisywane do tabeli. Pod koniec wyświetl tabele z posortowanymi imionami.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "narzedzia.h"
using namespace std;

string dzielniki = " .;\t";

int main()
{
    vector<string> imiona_i_nazwiska;

    cout << "Wprowadzaj imiona i nazwiska, ktore nastepnie bede formatowac(0 - zeby skonczyc): ";
    while(true)
    {
        string imie_nazwisko, imie, nazwisko;
        getline(cin, imie_nazwisko);
        if(imie_nazwisko == "0")
            break;

        size_t gdzie_dzielnik = imie_nazwisko.find_first_of(dzielniki);

        imie = imie_nazwisko.substr(0, gdzie_dzielnik);
        if(gdzie_dzielnik != string::npos)
            nazwisko = imie_nazwisko.substr(gdzie_dzielnik+1);

        
        if (!imie.empty())
        {
            imie.at(0) = toupper(imie.at(0));
        }
        if(!nazwisko.empty())
        {
            nazwisko.at(0) = toupper(nazwisko.at(0));
        }

        auto zmniejszacz = [](char &c)
        {
            c = tolower(c);
        };

        if(imie.size() > 1)
        for_each(imie.begin() + 1, imie.end(), zmniejszacz);
        if(nazwisko.size() > 1)
        for_each(nazwisko.begin() + 1, nazwisko.end(), zmniejszacz);

        imiona_i_nazwiska.push_back(imie + " " + nazwisko);
    }

    drukuj(imiona_i_nazwiska);
}