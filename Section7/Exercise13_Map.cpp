// Zadanie 13 - Ksiazka telefoniczna. Posiadasz okreslony zbior danych map<string, int>, w ktorym string okresla imie przyjaciela(ki) a int - jego numer telefonu bez (+48). Niech uzytkownik wprowadza
// imiona osob, ktorych numer telefonu potrzebuje, a zwrotnie dostaje informacje dotyczaca tego, jaki ten przyjaciel(ka) ma numer telefonu.
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
//************************************************************************************************************************************************************************
map<string, int> ksiazka_telefoniczna = {{"Piotr", 545234523},
                                         {"Damian", 242533435},
                                         {"Pawel", 235334353},
                                         {"Kornel", 234898098},
                                         {"Olaf", 245332445},
                                         {"Eustachy", 345563234},
                                         {"Oskar", 345609454},
                                         {"Aureliusz", 335345231},
                                         {"Daniel", 134523533}};
//************************************************************************************************************************************************************************
int main()
{
    while(true) {
        cout << "Wprowadz imie: ";
        string imie;
        cin >> imie;

        if(imie == "q")
            return 0;

        if (auto pos = ksiazka_telefoniczna.find(imie); pos != ksiazka_telefoniczna.end())
        {
            cout << "Numer telefonu: +48" << pos->second << endl;
        } else {
            cout << "Nie znaleziono. Sprobuj ponownie lub wyjdz \'q\'" << endl;
        }
    }
}