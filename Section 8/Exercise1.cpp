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

#include <algorithm>
#include <iterator>
#include <random>
#include <iomanip>
#include <type_traits>
#include <functional>
using namespace std;
//***************************************************************************************************************************************
using jednostka = int;
using kontener = multiset<jednostka>;

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
kontener pobierz_liczby(string napis = "")
{
    cout << napis;

    kontener liczby;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), inserter(liczby, liczby.begin()));
    cin.clear();
    cin.ignore();
    return liczby;
}

//***************************************************************************************************************************************
kontener::iterator przestaw_index(kontener& zbior, int gdzie = 0)
{
    kontener::iterator pos = zbior.begin();
    for (int i = 0; i < gdzie; i++)
    {
        pos++;
    }
    return pos;
}

//***************************************************************************************************************************************
bool praca_z_plikiem(kontener &zbior, tryb_pracy tryb)
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

    return false;
}

//***************************************************************************************************************************************
kontener daj_kontener_liczb_losowych(int ilosc_liczb = 1000, int from = 0, int to = 1000)
{
    kontener liczby_losowe;
    auto insert_pointer = inserter(liczby_losowe, liczby_losowe.begin());
    for (int i = 0; i < ilosc_liczb; i++)
    {
        *insert_pointer++ = rand() % (to-from) + from;
    }
    return liczby_losowe;
}

//***************************************************************************************************************************************
kontener daj_kontener_liczb_losowych_od_uzytkownika()
{
    int ilosc_liczb = pobierz_liczbe("Podaj ilosc losowych liczb: ");

    int zakres_dolny = pobierz_liczbe("Podaj zakres dolny losowosci: ");
    int zakres_gorny = pobierz_liczbe("Podaj zakres gorny losowosci: ");
    return daj_kontener_liczb_losowych(ilosc_liczb, zakres_dolny, zakres_gorny);
}

//***************************************************************************************************************************************
void wypisz(const kontener &zbior, int liczba_kolumn = 25, int odstep_pomiedzy = 2)
{

    int maksymalna_l = *(max_element(zbior.cbegin(), zbior.cend()));

    int szerokosc_poj_liczby = to_string(maksymalna_l).size() + odstep_pomiedzy;
    int wysokosc = zbior.size() / liczba_kolumn;
    int pozostalosc = zbior.size() % liczba_kolumn;

    auto pos = zbior.begin();

    for (int y = 0; y <= wysokosc; y++)
    {
        // pozostale liczby
        if(y == wysokosc)
        {
            liczba_kolumn = pozostalosc;
        }

        // zwykle liczby
        for (int x = 0; x < liczba_kolumn; ++x)
        {
            cout << setw(szerokosc_poj_liczby) << *pos;
            pos++;
        }
        cout << endl;
    }
}

//***************************************************************************************************************************************
// Dla wyszystkich pozostalych
template <class T>
bool sortowanie(T& zbior)
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
///////////////////////////////////////////////////////////////////////////////////////
//Specjalizajca - list
template <>
bool sortowanie(list<jednostka>& zbior)
{
    int odpowiedz = pobierz_liczbe("Wybierz typ sortowania (1 - <, 2 - >): ");
    switch (odpowiedz)
    {
    case 1:
        zbior.sort();
        break;
    case 2:
        zbior.sort(greater<int>());
        break;
    default:
        cout << "Odpowiedz niezrozumiala. " << endl;
        return false;
        break;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////
//Specjalizajca - forward list
template <>
bool sortowanie(forward_list<jednostka>& zbior)
{
    int odpowiedz = pobierz_liczbe("Wybierz typ sortowania (1 - <, 2 - >): ");
    switch (odpowiedz)
    {
    case 1:
        zbior.sort();
        break;
    case 2:
        zbior.sort(greater<int>());
        break;
    default:
        cout << "Odpowiedz niezrozumiala. " << endl;
        return false;
        break;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////
//Specjalizajca - set
template <>
bool sortowanie(set<jednostka>& zbior)
{
    cout << "Nie wolno sortowac set!" << endl;
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////
//Specjalizajca - set
template <>
bool sortowanie(multiset<jednostka>& zbior)
{
    cout << "Nie wolno sortowac multiset!" << endl;
    return true;
}

//***************************************************************************************************************************************
enum class tryb_usuwania
{
    jedna_liczba,
    przedzial,
    zakres
};
////////////////////////////////////////////////////////////////////////
//Process dla wiekszosci
template <class T>
void usuwanie_proces(T& zbior, typename T::iterator pos_b, typename T::iterator pos_e, function<bool(int)> funkcja, tryb_usuwania jaki)
{
    if(jaki == tryb_usuwania::jedna_liczba || jaki == tryb_usuwania::przedzial)
    {
        zbior.erase(remove_if(pos_b, pos_e, funkcja), pos_e);
    } else {
        zbior.erase(pos_b, pos_e);
    }
}
////////////////////////////////////////////////////////////////////////
//Process dla set
template <>
void usuwanie_proces(set<jednostka>& zbior, typename set<jednostka>::iterator pos_b, typename set<jednostka>::iterator pos_e, function<bool(int)> funkcja, tryb_usuwania jaki)
{
    if(jaki == tryb_usuwania::jedna_liczba || jaki == tryb_usuwania::przedzial)
    {
        for(auto pos = zbior.begin(); pos != zbior.end();)
        {
            if(funkcja(*pos) == true)
            {
                pos = zbior.erase(pos);
            } else {
                pos++;
            }
        }
    } else {
        zbior.erase(pos_b, pos_e);
    }
}
////////////////////////////////////////////////////////////////////////
//Process dla multiset
template <>
void usuwanie_proces(multiset<jednostka>& zbior, typename set<jednostka>::iterator pos_b, typename set<jednostka>::iterator pos_e, function<bool(int)> funkcja, tryb_usuwania jaki)
{
    if(jaki == tryb_usuwania::jedna_liczba || jaki == tryb_usuwania::przedzial)
    {
        for(auto pos = zbior.begin(); pos != zbior.end();)
        {
            if(funkcja(*pos) == true)
            {
                pos = zbior.erase(pos);
            } else {
                pos++;
            }
        }
    } else {
        zbior.erase(pos_b, pos_e);
    }
}

////////////////////////////////////////////////////////////////////////
bool usuwanie_uniwersalne(kontener& zbior, tryb_usuwania jaki)
{
    int arg1 = 0;
    int arg2 = 0;
    kontener::iterator pos;

    bool czy_duzo = true;

    auto pos_b = zbior.begin();
    auto pos_e = zbior.end();

    function<bool(int)> funkcja;

    if(jaki == tryb_usuwania::jedna_liczba)
    {
        arg1 = pobierz_liczbe("1 - jedna liczbe, 0 - wiele takich samych liczb:");
        arg2 = pobierz_liczbe("Wpisz liczbe: ");

        funkcja = [&](int liczba)
                  { if(liczba == arg2 && czy_duzo)
                {
                    if(arg1 == 1)
                        czy_duzo = false;
                    return true;
                } else {
                    return false;
                } };

    } else if (jaki == tryb_usuwania::przedzial)
    {
        arg1 = pobierz_liczbe("Podaj poczatek zakresu (wlacznie): ");
        arg2 = pobierz_liczbe("Podaj gorny zakres (wlacznie): ");

        funkcja = [=](int liczba)
                          {
            if(liczba >= arg1 && liczba <= arg2) {
                return true;
            } else {
                return false;
            } };

    } else if (jaki == tryb_usuwania::zakres)
    {
        arg1 = pobierz_liczbe("Podaj poczatkowy index (wlacznie): ");
        arg2 = pobierz_liczbe("Podaj gorny index (wlacznie): ");

        pos_b = przestaw_index(zbior, --arg1);
        pos_e = przestaw_index(zbior, arg2);
    }

    usuwanie_proces(zbior, pos_b, pos_e, funkcja, jaki);

    return true;
}


//***************************************************************************************************************************************
bool usuwanie(kontener& zbior)
{
    int odpowiedz = pobierz_liczbe("Wybierz typ usuwania (1 - okreslona liczby(a), 2 - przedzial liczbowy, 3 - okres ot i do): ");
    switch (odpowiedz)
    {
    case 1:
        usuwanie_uniwersalne(zbior, tryb_usuwania::jedna_liczba);
        break;

    case 2:
        usuwanie_uniwersalne(zbior, tryb_usuwania::przedzial);
        break;

    case 3:
        usuwanie_uniwersalne(zbior, tryb_usuwania::zakres);
        break;

    default:
        return false;
        break;
    }
    return true;
}


//***************************************************************************************************************************************
bool wstawianie_liczb(kontener &zbior, bool czy_losowe = true)
{
    kontener liczby;
    if(czy_losowe)
        liczby = daj_kontener_liczb_losowych_od_uzytkownika();
    else
        liczby = pobierz_liczby("Wprowadz liczby a na koniec wprowadz symbol 'q': ");

    int odpowiedz = pobierz_liczbe("Wprowadz gdzie chcesz wstawic liczby (1 - poczatek, 2 - srodek, 3 - koniec, 4 - wpisz index):");
    auto pos = zbior.begin();
    switch (odpowiedz)
    {
    case 1:
        break;
    case 2:
        pos = przestaw_index(zbior, liczby.size() / 2);
        break;
    case 3:
        pos = zbior.end();
        break;

    case 4:
        odpowiedz = pobierz_liczbe("Wprowadz index: ");
        pos = przestaw_index(zbior, odpowiedz);
        break;

    default:
        return false;
        break;
    }

    copy(liczby.begin(), liczby.end(), inserter(zbior, pos));
    return true;
}

//***************************************************************************************************************************************
bool wstawianie(kontener& zbior)
{
    int odpowiedz = pobierz_liczbe("1 - liczby losowe, 2 - wprowadzic liczby: ");
    switch (odpowiedz)
    {
    case 1:
        wstawianie_liczb(zbior);
        break;
    case 2:
        wstawianie_liczb(zbior, false);
        break;

    default:
        return false;
        break;
    }
    return true;
}
//***************************************************************************************************************************************
bool znajdz_liczbe(kontener& zbior, bool zakres = false)
{
    if(zakres)
    {
        int dolna_liczba = pobierz_liczbe("Od (wlacznie):");

        int gorna_liczba = pobierz_liczbe("Do (wlacznie):");

        int ilosc_wystepowan = count_if(zbior.begin(), zbior.end(), [=](int liczba)
                                        { if(liczba >= dolna_liczba && liczba <= gorna_liczba)
                                        {
                                            return true;
                                        } else {
                                            return false;
                                        }});

        cout << "Ilosc wystepowan podanej liczby(liczb): " << ilosc_wystepowan << endl;
        return true;

    } else {
        int jaka_liczba = pobierz_liczbe("Wprowadz liczbe: ");
        int ilosc_wystepowan = count_if(zbior.begin(), zbior.end(), [=](int liczba)
                                        { return liczba == jaka_liczba ? true : false; });

        cout << "Ilosc wystepowan podanej liczby(liczb): " << ilosc_wystepowan << endl;
        return true;
    }
}

//***************************************************************************************************************************************
bool znajdz(kontener &zbior)
{
    int odpowiedz = pobierz_liczbe("1 - Ilosc wystepowan pojedynczej liczby, 2 - Ilosc wystepowan liczb z zakresu: ");
    switch (odpowiedz)
    {
    case 1:
        znajdz_liczbe(zbior);
        break;
    case 2:
        znajdz_liczbe(zbior, true);
        break;

    default:
        return false;
        break;
    }
    return true;
}

//***************************************************************************************************************************************
bool zapisz(kontener& zbior)
{
    int odpowiedz = pobierz_liczbe("1 - Zapisz zbior, 2 - odczytaj: ");
    switch (odpowiedz)
    {
    case 1:
        praca_z_plikiem(zbior, tryb_pracy::zapis);
        break;
    
    case 2:
        praca_z_plikiem(zbior, tryb_pracy::odczyt);
        break;

    default:
        return false;
        break;
    }
    return true;
}

//***************************************************************************************************************************************
int main()
{
    srand(time(NULL));

    kontener liczby = daj_kontener_liczb_losowych_od_uzytkownika();
    while (true)
    {
        wypisz(liczby);
        int odpowiedz = pobierz_liczbe("\t1 - Sortowanie\n\t2 - Usuwanie\n\t3 - Wstawianie\n\t4 - Znajdywanie\n\t5 - Zapisywanie/Odczyt\n\t6 - Wyjscie:");
        switch (odpowiedz)
        {
        case 1:
            sortowanie(liczby);
            break;
        case 2:
            usuwanie(liczby);
            break;
        case 3:
            wstawianie(liczby);
            break;
        case 4:
            znajdz(liczby);
            break;
        case 5:
            zapisz(liczby);
            break;
        case 6:
            exit(0);

        default:
            break;
        }
    }
    
}