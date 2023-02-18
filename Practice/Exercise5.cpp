// Zadanie 5 - Generator losowych liczb w zadanym przedziale. Niech uzytkwonik zgeneruje okreslone liczby losowe i bedzie mogl ich
// posortowac, zapisac/odczytac, dodac w okreslone miejsce.
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using jednostka = int64_t;
using kontener = list<jednostka>;
//******************************************************************************************************************************************************************
template <typename T>
T wprowadzenie(string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//******************************************************************************************************************************************************************
template <>
string wprowadzenie(string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);
    return zmienna;
}
//********************************************************************************************************************************
kontener daj_liczby_losowe()
{
    srand(time(NULL));

    int ilosc = wprowadzenie<int>("Podaj ilosc liczb losowych: ");

    int dol = wprowadzenie<int>("Podaj dolny zakres: ");
    int gora = wprowadzenie<int>("Podaj gorny zakres: ");

    vector<jednostka> liczby;
    for (int i = 0; i < ilosc; i++)
    {
        liczby.push_back(rand() % (gora - dol) + dol);
    }

    kontener normalne_liczby;
    copy(liczby.begin(), liczby.end(), inserter(normalne_liczby, normalne_liczby.begin()));

    return normalne_liczby;
}
//********************************************************************************************************************************
void wypisz_dzialania()
{
    cout << "1 - sortowanie, 2 - zapis/odczyt, 3 - dodaj w okreslone miejsca,  4 - wyjscie" << endl;
}
//********************************************************************************************************************************
void wypisz_liczby(kontener liczby)
{
    for(const auto& elem : liczby)
    {
        cout << elem << ", ";
    }
    cout << endl;
}
//********************************************************************************************************************************
void sortowanie(kontener& liczby)
{
    int odpowiedz = wprowadzenie<int>("1 - <, 2 - >: ");

    if (odpowiedz != 1)
        liczby.sort(greater<jednostka>());
    else
        liczby.sort();
}
//********************************************************************************************************************************
void zapis_lub_odczyt(kontener& liczby)
{
    int odpowiedz = wprowadzenie<int>("1 - zapis, 2 - odczyt: ");

    if(odpowiedz == 1)
    {
        ofstream strm("liczby.data");

        for(const auto& elem : liczby)
        {
            strm << elem << endl;
        }

        cout << "Zapisano do liczby.data" << endl;
        strm.close();
    }
    else if (odpowiedz == 2)
    {
        ifstream strm("liczby.data");

        liczby.clear();

        copy(istream_iterator<jednostka>(strm), istream_iterator<jednostka>(), inserter(liczby, liczby.begin()));
        strm.close();
    }
}
//********************************************************************************************************************************
int main()
{
    kontener liczby = daj_liczby_losowe();

    while(true)
    {
        wypisz_liczby(liczby);
        wypisz_dzialania();
        
        int odpowiedz = wprowadzenie<int>("Wybierz dzialanie: ");

        switch (odpowiedz)
        {
        case 1:
            sortowanie(liczby);
            break;

        case 2:
            zapis_lub_odczyt(liczby);
            break;
        case 3:
            /* code */
            break;
        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }
}
