#include "manager.h"
#include <iostream>
using namespace std;
//***********************************************************************************************
template <typename T>
T wprowadzenie(std::string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//***********************************************************************************************
template <>
string wprowadzenie(std::string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);
    return zmienna;
}
//***********************************************************************************************
void wypisz_wynik_rzutu(const Player& gracz)
{
    cout << "Gracz " << gracz.daj_imie() << " wyrzucil: ";
    for(auto& elem : gracz.daj_koscie())
    {
        cout << elem << ", ";
    }
    cout << endl;
}
//***********************************************************************************************
void GameManager::rozpocznij_gre()
{
    // Niech zyje losowosc!
    srand(time(NULL));

    int ilosc_graczy = wprowadzenie<int>("Wprowadz ilosc graczy: ");

    while(ilosc_graczy-- > 0)
    {
        string imie = wprowadzenie<string>("Wprowadz imie gracza: " );
        int ilosc_kosci = wprowadzenie<int>("Wprowadz ilosc kosci: ");
        bool czy_k = wprowadzenie<int>("1 - Gracz, 2 - Komputer: ");

        gracze.insert(gracze.end(), Player(imie, czy_k, ilosc_kosci));
    }

    zacznij_kolejna_runde();
}
//***********************************************************************************************
void GameManager::zacznij_kolejna_runde()
{
    ilosc_rund++;

    cout << "Zaczynamy runde numer " << ilosc_rund << "!" << endl;

    for(auto& elem : gracze)
    {
        elem.rzucz_kosci();
        wypisz_wynik_rzutu(elem);
    }

    for(auto& elem : gracze)
    {
        ruch_gracza(elem);
    }

    wypisz_wyniki();

    for(const auto& elem : gracze)
    {
        if(ilosc_rund == elem.daj_ilosc_wygranych())
        {
            koniec_i_zwyciezca(elem);
        }
    }

    zacznij_kolejna_runde();
}
