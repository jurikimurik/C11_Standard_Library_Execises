// Zadanie 8 - Zagadki. Niech uzytkownik wprowadzi zbior zagadek, gdzie najpierw idzie linijka zagadki, a pod nim jest odpowiedz w formie
// tekstu lub liczby. Uzytkownik zadaje ilosc rund i musi dobrze odpowiedziec na zagadki. Pod koniec wypisz wynik uzytkownika.
#include <fstream>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
//****************************************************************************************************************************************
template <typename T>
T wprowadzenie(string napis)
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//****************************************************************************************************************************************
template <>
string wprowadzenie(string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);

    for_each(zmienna.begin(), zmienna.end(), [](char &c)
             { c = tolower(c); });

    return zmienna;
}
//****************************************************************************************************************************************
void do_malego(string& tekst)
{
    for_each(tekst.begin(), tekst.end(), [](char &c)
             { c = tolower(c); });
}
//****************************************************************************************************************************************
map<string, string> pobierz_zagadki()
{
    string nazwa = wprowadzenie<string>("Podaj nazwe pliku bez rozszerzenia: ");
    nazwa += ".ridd";

    map<string, string> zagadki;

    ifstream strm(nazwa);
    while (true)
    {
        string zagadka;
        getline(strm, zagadka);
        string odpowiedz;
        getline(strm, odpowiedz);

        do_malego(odpowiedz);

        if (!strm)
        {
            break;
        }
        zagadki.insert(make_pair(zagadka, odpowiedz));
    }

    return zagadki;
}
//****************************************************************************************************************************************
bool runda_zagadki(const map<string, string> &zagadki)
{
    int losowosc = rand() % zagadki.size();

    auto pozycja_zagadki = zagadki.begin();
    advance(pozycja_zagadki, losowosc);
    string zagadka = pozycja_zagadki->first;
    string odpowiedz = pozycja_zagadki->second;

    cout << endl
         << endl;
    cout << "Podana zagadka: " << zagadka << endl;

    string odpowiedz_uzytkownika = wprowadzenie<string>("Podaj odpowiedz: ");
    do_malego(odpowiedz_uzytkownika);

    if (odpowiedz_uzytkownika == odpowiedz)
    {
        cout << "Poprawnie!" << endl;
        return true;
    }
    else
    {
        cout << "Zle! Poprawna odpowiedz: " << odpowiedz << "!" << endl;
        return false;
    }

    return true;
}
//****************************************************************************************************************************************
int main()
{
    srand(time(NULL));

    map<string, string> zagadki = pobierz_zagadki();

    int ilosc_rund = wprowadzenie<int>("Podaj ilosc rund: ");
    int punkty = 0;
    while (ilosc_rund != 0)
    {
        bool zagadka_rozwiazana = runda_zagadki(zagadki);
        if (zagadka_rozwiazana)
            punkty += 100;

        ilosc_rund--;
    }

    cout << "Twoj wynik to: " << punkty << "!" << endl;
}