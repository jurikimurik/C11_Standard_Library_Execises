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

    string imie = wprowadzenie<string>("Wprowadz imie gracza: ");
    int ilosc_kosci = wprowadzenie<int>("Wprowadz ilosc kosci: ");

    gracze.insert(gracze.begin(), Player(imie, false, ilosc_kosci));

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

    cout << "Co chcesz zrobic? 1 - powtorka, 2 - wyjscie. " << endl;
    int odpowiedz = wprowadzenie<int>("Wybierz dzialanie: ");
    switch (odpowiedz)
    {
    case 1:
        zacznij_kolejna_runde();
        break;

    default:
        break;
    }
}
