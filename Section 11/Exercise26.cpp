// Zadanie 26 - Wstawiasz. Posiadasz posortowany ciąg liczb. Pozwól użytkownikowi dodawać tam liczby. Pod koniec scal
// Ten ciąg z innym posortowanym i generowanym losowo ciągiem.
#include "narzedzia.h"
#include <vector>
using namespace std;

void dodaj_liczbe(vector<int>& liczby)
{
    int wpr = wprowadzenie<int>("Liczba do dodania: ");

    auto pos = upper_bound(liczby.begin(), liczby.end(), wpr);
    liczby.insert(pos, wpr);
}

void koniec(vector<int>& liczby)
{
    auto liczby_inne = generuj_ciag_liczbowy<vector<int>>(0, 100, 20);

    sort(liczby_inne.begin(), liczby_inne.end());

    drukuj(liczby_inne, "", "\n");

    vector<int> nowy_ciag;
    merge(liczby.begin(), liczby.end(), liczby_inne.begin(), liczby_inne.end(), back_inserter(nowy_ciag));

    drukuj(nowy_ciag, "Koncowy ciag: ", "");
    exit(0);
}

int main()
{
    auto liczby = generuj_ciag_liczbowy<vector<int>>(0, 100, 20);

    sort(liczby.begin(), liczby.end());

    while(true)
    {
        drukuj(liczby);

        int odpowiedz = wprowadzenie<int>("1 - dodaj liczbe, 2 - koniec: ");

        switch (odpowiedz)
        {
        case 1:
            dodaj_liczbe(liczby);
            break;
        case 2:
            koniec(liczby);
            break;

        default:
            break;
        }


    }
}