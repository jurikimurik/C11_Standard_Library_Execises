// Zadanie 2 - Znajdywanka. Masz plik danych z slowami. Zadaniem uztkownika jest w okreslonej ilosci rund podac na ktorym miejscu znajduje sie podana litera i zaliczyc poziom
// (dostajes punkty) lub nie dostajesz nic. Na koncu wypisz wynik.
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <chrono>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using jednostka = string;
using kontener = list<jednostka>;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
kontener zbior;
int punkty = 0;
//***************************************************************************************************************************************************************************
template <typename T>
auto wprowadzenie(string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//***************************************************************************************************************************************************************************
void wypisz_zbior(kontener zb = zbior)
{
    for(const auto& elem : zb)
    {
        cout << elem << " - ";
    }
    cout << endl;
}
//***************************************************************************************************************************************************************************
bool wgraj_dane(string nazwa)
{
    nazwa += ".tekst";

    ifstream strm (nazwa);
    if(!strm)
    {
        cout << "Nie udalo sie zaladowac, sprobuj ponownie" << endl;
        return false;
    }

    copy(istream_iterator<string>(strm), istream_iterator<string>(), inserter(zbior, zbior.begin()));

    return true;
}
//***************************************************************************************************************************************************************************
pair<bool, chrono::system_clock::time_point> runda(int ilosc_rund, kontener zb = zbior)
{
    srand(time(NULL));
    
    cout << "\tRunda " << ilosc_rund << "!" << endl;

    //slowo
    int losowosc = rand() % zb.size();
    auto pos = zb.begin();
    advance(pos, losowosc);
    string slowo = *pos;

    //litera
    losowosc = rand() % slowo.size();
    char znak = slowo.at(losowosc);

    cout << slowo << " - podaj na ktorym miejscu jest pierwsza litera \'" << znak << "\': ";

    //Liczymy czas - start
    auto start_czas = chrono::system_clock::now();

    int odpowiedz = wprowadzenie<int>();

    if(odpowiedz == losowosc + 1)
    {
        cout << "Dobrze!" << endl;
        return make_pair(true, start_czas);
    } else {
        cout << "Zle!" << endl;
        return make_pair(false, start_czas);
    }


}
//***************************************************************************************************************************************************************************
void wynik(int punktacja = punkty)
{
    cout << "Zdobyles " << punktacja << " punktow! Brawo!" << endl;
}
//***************************************************************************************************************************************************************************
int punktacja(pair<bool, chrono::system_clock::time_point> inforamcje)
{
    if(!inforamcje.first)
        return 0;
    
    auto maksymalny_czas = chrono::seconds(5);
    int wspolczynnik = 1000;

    int maksymalna_punktacja = maksymalny_czas.count() * wspolczynnik;
    int minimalna_punktacja = maksymalny_czas.count() * wspolczynnik / 10;
    
    int punkty = maksymalna_punktacja - chrono::duration_cast<chrono::milliseconds>((chrono::system_clock::now() - inforamcje.second)).count();

    return punkty > 0 ? punkty : minimalna_punktacja;
}
//***************************************************************************************************************************************************************************
int main()
{
    while(!wgraj_dane(wprowadzenie<string>("Wpisz nazwe pliku: ")));

    wypisz_zbior();

    size_t ilosc_rund = wprowadzenie<size_t>("Wpisz ilosc rund: ");

    while(ilosc_rund > 0)
    {   
        punkty += punktacja(runda(ilosc_rund, zbior));
        ilosc_rund--;
    }

    wynik(punkty);
}