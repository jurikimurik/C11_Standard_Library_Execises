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

    int licznik = 1;
    int ilosc_spacji = 20;
    int powtorzenia = 1;
    auto pos = liczby.begin();
    for (int i = 0, wypisano = 0; i < liczby.size(); ++i, pos++)
    {

        cout << *pos << " ";
        wypisano++;

        if(wypisano == licznik)
        {
           cout << endl;
           wypisano = 0;
           licznik *= 2;
        }
    }
}
//************************************************************************************************************************************
int main()
{
    vector<int> liczby = pobierz_liczby();

    wypisz_jako_stog(liczby);
}