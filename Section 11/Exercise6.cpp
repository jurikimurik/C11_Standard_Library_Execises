// Zadanie 6 - Inwentaryzacja. Wpisz przedmioty w postaci „przedmiot - ilosc”. Takie same przedmioty automatycznie do 
// siebie się dodają a na końcu wypisz wynik (liste) wszystkich przedmiotów i ich ilosc.
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
//**************************************************************************************************************
template <typename T>
T pobierz(string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//**************************************************************************************************************
template <>
string pobierz(string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);

    for_each(zmienna.begin(), zmienna.end(), [](char &c)
             { c = tolower(c); });

    return zmienna;
}
//**************************************************************************************************************
void wypisz(const map<string, int>& mapa)
{
    if(mapa.empty())
        return;

    for(const auto& elem : mapa)
    {
        cout << elem.first << " - " << elem.second << endl;
    }
}
//**************************************************************************************************************
int main()
{
    map<string, int> inwentarz;

    cout << "Zeby przerwac wprowadzenie, wpisz 'koniec' oraz liczbe '0'!" << endl;
    while (true)
    {
        auto para = make_pair(pobierz<string>("Wpisz nazwe przedmiotu: "), pobierz<int>("Wpisz ilosc przedmiotu: "));

        if(para.first == "koniec" && para.second == 0)
            break;

        inwentarz[para.first] += para.second;
        if(inwentarz[para.first] <= 0)
        {
            cout << "Ilosc " << para.first << " jest mniejsza lub rowna zeru - usuwam!" << endl;
            inwentarz.erase(para.first);
        }
    }

    wypisz(inwentarz);
}
