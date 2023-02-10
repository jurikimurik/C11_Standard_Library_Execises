// Zadanie 1 - Baza danych losowych liczb. Niech program zgeneruje do pliku liczby losowe o ilosci i rozrzucie wpisanym przez uzytkownika.
// Nastpenie wyswietl cala baze danych liczbowych w ladnych kilku kolumnach i pozwol uztkownikowi na: 1 - sortowanie > / < lub losowo, 
// 2 - usuwanie okreslonego elementu / usuwanie liczb w zadanym okresie, 3 - wstawianie kolejnych liczb losowych / wpisanych przez 
// uzytkownika, 4 - znajdywanie wystepowan okreslonej liczby / liczb z zakresu, 5 - zapis do pliku bazy danych / zaladownie z pliku
#include <iostream>
#include <fstream>

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>


#include <algorithm>
#include <iterator>
#include <random>
#include <iomanip>
#include <type_traits>
using namespace std;
//***************************************************************************************************************************************
using kontener = vector<int>;

//***************************************************************************************************************************************
enum class tryb_pracy
{
    zapis,
    odczyt
};

//***************************************************************************************************************************************
int pobierz_liczbe(string napis = "")
{
    cout << napis;
    int l;
    cin >> l;
    return l;
}

//***************************************************************************************************************************************
bool praca_z_plikiem(kontener& zbior, tryb_pracy tryb)
{
    if(tryb == tryb_pracy::zapis) {
        ofstream strm("liczby.data");

        copy(zbior.begin(), zbior.end(), ostream_iterator<int>(strm, " "));

        strm.close();
        if (strm)
            return true;
        else
            return false;
    } else if (tryb == tryb_pracy::odczyt) {
        ifstream strm("liczby.data");

        zbior.clear();

        copy(istream_iterator<int>(strm), istream_iterator<int>(), inserter(zbior, zbior.begin()));

        strm.close();
        if (strm)
            return true;
        else
            return false;
    }

    
    
}

//***************************************************************************************************************************************
kontener daj_kontener_liczb_losowych(int ilosc_liczb = 1000, int from = 0, int to = 1000)
{
    kontener liczby_losowe;
    auto insert_pointer = inserter(liczby_losowe, liczby_losowe.begin());
    for (int i = 0; i < ilosc_liczb; i++)
    {
        *insert_pointer++ = rand() % to + from;
    }
    return liczby_losowe;
}

//***************************************************************************************************************************************
void wypisz(const kontener &zbior, int liczba_kolumn = 25, int odstep_pomiedzy = 2)
{

    int maksymalna_l = *(max_element(zbior.cbegin(), zbior.cend()));

    int szerokosc_poj_liczby = to_string(maksymalna_l).size() + odstep_pomiedzy;
    int wysokosc = zbior.size() / liczba_kolumn;

    auto pos = zbior.begin();

    for (int y = 0; y < wysokosc; y++)
    {
        for (int x = 0; x < liczba_kolumn; ++x)
        {
            cout << setw(szerokosc_poj_liczby) << *pos;
            pos++;
        }
        cout << endl;
    }
}

//***************************************************************************************************************************************
bool sortowanie(kontener& zbior)
{
    int odpowiedz = pobierz_liczbe("Wybierz typ sortowania (1 - <, 2 - >, 3 - losowo): ");
    switch (odpowiedz)
    {
    case 1:
        sort(zbior.begin(), zbior.end());
        break;
    case 2:
        sort(zbior.begin(), zbior.end(), greater<int>());
        break;
    case 3:
        shuffle(zbior.begin(), zbior.end(), mt19937());
        break;

    default:
        cout << "Odpowiedz niezrozumiala. " << endl;
        return false;
        break;
    }
    return true;
}

//***************************************************************************************************************************************
bool usuwanie_liczba(kontener& zbior)
{
    int odpowiedz = pobierz_liczbe("1 - jedna liczbe, 2 - wiele takich samych liczb:");
    int ktora_liczba = pobierz_liczbe("Wpisz liczbe: ");

    if (odpowiedz == 1)
    {
        auto pos = find(zbior.begin(), zbior.end(), ktora_liczba);
        zbior.erase(pos);
    }
    else if (odpowiedz == 2)
    {
        zbior.erase (remove_if(zbior.begin(), zbior.end(), [=](int liczba)
                  { if(liczba == ktora_liczba)
                {
                    return true;
                } else {
                      return false;
                } }), zbior.end());
    }
    return true;
}
//***************************************************************************************************************************************
bool usuwanie_przedzial(kontener& zbior)
{
    int poczatek_zakresu = pobierz_liczbe("Podaj poczatek zakresu: ");
    int koniec_zakresu = pobierz_liczbe("Podaj gorny zakres: ");

    zbior.erase(remove_if(zbior.begin(), zbior.end(), [=](int liczba)
                          {
            if(liczba > poczatek_zakresu && liczba < koniec_zakresu) {
                return true;
            } else {
                return false;
            } }),
                zbior.end());
    return true;
}

//***************************************************************************************************************************************
bool usuwanie_okresu(kontener& zbior)
{
    int poczatek_zakresu = pobierz_liczbe("Podaj poczatkowy index: ");
    int koniec_zakresu = pobierz_liczbe("Podaj gorny index: ");

    auto pos_b = zbior.begin();
    auto pos_e = zbior.end();
    for (int i = 0; i < poczatek_zakresu; ++i)
    {
        pos_b++;
    }
    for (int i = 0; i < koniec_zakresu; ++i)
    {
        pos_e++;
    }

    zbior.erase(pos_b, pos_e);
    return true;
}

//***************************************************************************************************************************************
bool usuwanie(kontener& zbior)
{
    int odpowiedz = pobierz_liczbe("Wybierz typ usuwania (1 - okreslona liczby(a), 2 - przedzial liczbowy, 3 - okres ot i do): ");
    switch (odpowiedz)
    {
    case 1:
        usuwanie_liczba(zbior);
        break;

    case 2:
        usuwanie_przedzial(zbior);
        break;

    case 3:
        usuwanie_okresu(zbior);
        break;

    default:
        break;
    }
}

//***************************************************************************************************************************************
int main()
{
    srand(time(NULL));
    kontener liczby = daj_kontener_liczb_losowych(101, 1, 5);
    praca_z_plikiem(liczby, tryb_pracy::zapis);
    wypisz(liczby);
    usuwanie(liczby);
    wypisz(liczby);
}