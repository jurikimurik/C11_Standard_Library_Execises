// Zadanie 7 - Zgadywanka. Pozwol uzytkownikowi zaladowac zbior slow. Nastepnie niech wprowadzi ilosc rund. Sens rozrywki polega na tym, ze
// zostaje wypisane slowo bez jakiejs jego czesci. Poczatkowej, srodkowej lub koncowej. Ta czesc zostaje wypisana pod slowem. Uzytkownik
// musi wpisac gdzie trzeba ta czesc wpisac, by dostac sensowne slowo. Za kazda poprawna odpowiedz dostaje punkt. Na koniec wyswietl wynik.
#include <fstream>
#include <vector>
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
vector<string> pobierz_slownik()
{
    string nazwa = wprowadzenie<string>("Podaj nazwe pliku bez rozszerzenia: ");
    nazwa += ".dict";

    vector<string> slownik;

    ifstream strm(nazwa);
    while (strm)
    {
        string slowo;
        strm >> slowo;
        slownik.push_back(slowo);
    }
    slownik.pop_back();

    return slownik;
}
//****************************************************************************************************************************************
bool runda_zgadywanki(const vector<string>& slownik)
{
    int losowosc = rand() % slownik.size();
    string slowo = slownik.at(losowosc);

    int rodzaj = 0;
    string pod_slowo;
    int ilosc = rand() % 2 + 2;
    losowosc = rand() % 3 + 1;

    auto od = slowo.begin();
    auto az_do = slowo.begin() + ilosc;

    if(losowosc == 1)
    {
        rodzaj = 1;
    }
    else if (losowosc == 2)
    {
        od += slowo.size() / 2;
        az_do += slowo.size() / 2;
        rodzaj = 2;
    }
    else
    {
        od = slowo.end() - ilosc;
        az_do = slowo.end();
        rodzaj = 3;
    }

    copy(od, az_do, back_inserter(pod_slowo));
    slowo.erase(od, az_do);

    cout << endl
         << endl;
    cout << "Podane slowo: " << slowo << endl;
    cout << "Pod-slowo: " << pod_slowo << endl;
    cout << "Gdzie nalezy wstawic pod-slowo?" << endl;

    int odpowiedz = wprowadzenie<int>("1 - przed, 2 - w srodku, 3 - na koncu: ");
    if(odpowiedz == rodzaj)
    {
        cout << "Poprawnie!" << endl;
        return true;
    } else {
        cout << "Zle!" << endl;
        return false;
    }

    return true;
}
//****************************************************************************************************************************************
int main()
{
    srand(time(NULL));

    vector slownik = pobierz_slownik();

    int ilosc_rund = wprowadzenie<int>("Podaj ilosc rund: ");
    int punkty = 0;
    while(ilosc_rund != 0)
    {
        bool zagadka_rozwiazana = runda_zgadywanki(slownik);
        if(zagadka_rozwiazana)
            punkty += 100;

        ilosc_rund--;
    }

    cout << "Twoj wynik to: " << punkty << "!" << endl;
}