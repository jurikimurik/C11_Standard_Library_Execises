// Zadanie 3 - Stog. Z zadanych liczb przez uzytkownika stworz stog i wypisz go na ekranie. Stworz wizualizacje stogu.
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//************************************************************************************************************************************
vector<int> pobierz_liczby()
{
    vector<int> liczby;

    cout << "Wprowadzaj liczby oddzielajac ich spacjami a nastepnie wpisz 'q': ";
    while (cin)
    {
        int liczba;
        cin >> liczba;
        liczby.push_back(liczba);
    }
    liczby.pop_back();

    return liczby;
}
//************************************************************************************************************************************
void wypisz_jako_stog(vector<int> liczby)
{
    make_heap(liczby.begin(), liczby.end());
    
    int ilosc_poziomow = 0;
    int mnoznik = 1;
    while (mnoznik <= liczby.size())
    {
        mnoznik *= 2;
        ilosc_poziomow++;
    }

    int odstep = 1;
    for (int i = 2; i < ilosc_poziomow; ++i)
    {
        odstep = odstep * 2 + 2;
    }

    cout << "Ilosc poziomow: " << ilosc_poziomow << endl;
    cout << "Odstep: " << odstep << endl;

    int licznik = 1;
    auto pos = liczby.begin();
    for (int i = 0, stary_odstep = odstep, wypisano = 0; i < liczby.size(); ++i, pos++)
    {
        for (int x = 0; x < odstep && wypisano == 0; ++x)
        {
            cout << " ";
        }

        cout << *pos;
        wypisano++;

        int dlugosc_liczby = to_string(*pos).size();

        for (int x = 0; x <= stary_odstep - dlugosc_liczby + 1 && i != 0 && wypisano != licznik; ++x)
        {
            cout << " ";
        }

            if (wypisano == licznik)
            {
                cout << endl;
                wypisano = 0;
                licznik *= 2;

                stary_odstep = odstep;
                odstep = (odstep - 2) / 2;
                if (odstep < 0)
                    odstep = 0;
            }
    }
}
//************************************************************************************************************************************
int main()
{
    vector<int> liczby = pobierz_liczby();

    wypisz_jako_stog(liczby);
}