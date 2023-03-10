// Zadanie 25 - Poszukiwacz. Jest ciąg liczb generowanych losowo. Następnie jest posortowany. Niech użytkownik wprowadzi ciąg i sprawdzi 
// czy zadany ciąg jest w nim.
#include "narzedzia.h"
#include <vector>
using namespace std;

void sprawdz_liczbe(vector<int>& liczby)
{
    int liczba = wprowadzenie<int>("Wprowadz liczby: ");
    if(binary_search(liczby.begin(), liczby.end(), liczba))
    {
        cout << "Liczba JEST w ciagu" << endl;
    } else {
        cout << "Liczba NIE JEST w ciagu" << endl;
    }
}

void sprawdz_ciag(vector<int> liczby)
{
    auto wprowadzony_ciag = wprowadz_ciag<vector<int>>("Wprowadz ciag: ");
    if (includes(liczby.begin(), liczby.end(), wprowadzony_ciag.begin(), wprowadzony_ciag.end()))
    {
        cout << "Zadany ciag jest w liczbach" << endl;
    } else {
        cout << "Zadanego ciagu NIE MA w liczbach" << endl;
    }
}

int main()
{
    auto liczby = generuj_ciag_liczbowy<vector<int>>(10, 25, 20);

    sort(liczby.begin(), liczby.end());

    while(true)
    {
        drukuj(liczby, "", "\n");

        int odpowiedz = wprowadzenie<int>("1 - sprawdz czy jest liczba, 2 - sprawdz czy jest podany ciag, 3 - koniec: ");

        switch (odpowiedz)
        {
        case 1:
            sprawdz_liczbe(liczby);
            break;
        case 2:
            sprawdz_ciag(liczby);
            break;
        case 3:
            return 0;
            break;

        default:
            break;
        }
    }
}