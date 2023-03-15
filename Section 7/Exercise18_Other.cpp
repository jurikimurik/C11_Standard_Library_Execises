// Zadanie 18 - Wielkie porownanie. Niech uzytkownik wpisze wielkosc dla kazdego z kontenerow STL. Kazdy z nich musi zostac uzupelniony liczbami i szybkosc tej pracy musi byc wypisana.
// Nastepnie pozwol uzytkownikowi sprawdzic, ktory z podanych kontenerow najlepiej przeprowadza sortowanie/ktory najlepiej wklada liczby na poczatek/na koniec/po srodku (przy wkladaniu
// liczb niech uzytkownik sam okresli ilosc liczb)/usuwanie okreslonej liczby elementow.
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <algorithm>
#include <iostream>
using namespace std;
using namespace std::chrono;
//*****************************************************************************************************************************************************************************************
vector<int> wektor;
deque<int> kolejka;
list<int> lista;
forward_list<int> lista_do_przodu;
map<int, int> mapa;
set<int> zbior;
unordered_map<int, int> nieuporz_mapa;
unordered_set<int> nieuporz_zbior;
//*****************************************************************************************************************************************************************************************
enum class tryb_wkladania
{
    poczatek,
    srodek,
    koniec
};

//*****************************************************************************************************************************************************************************************
auto zacznij_mierzyc()
{
    return system_clock::now();
}

//*****************************************************************************************************************************************************************************************
void skoncz_i_wypisz_roznice(time_point<system_clock> czas, string napis)
{
    cout << napis << duration_cast<milliseconds>(system_clock::now() - czas).count() << endl;
}

//*****************************************************************************************************************************************************************************************
void uzupelnienie(int liczba)
{
    auto czas = zacznij_mierzyc();
    for (int i = 0; i < liczba; ++i)
    {
        wektor.push_back(i);
    }
    skoncz_i_wypisz_roznice(czas, "Vector: ");

    czas = zacznij_mierzyc();
    for (int i = 0; i < liczba; ++i)
    {
        kolejka.push_back(i);
    }
    skoncz_i_wypisz_roznice(czas, "Kolejka: ");

    czas = zacznij_mierzyc();
    for (int i = 0; i < liczba; ++i)
    {
        lista.push_back(i);
    }
    skoncz_i_wypisz_roznice(czas, "Lista: ");

    czas = zacznij_mierzyc();
    for (int i = 0; i < liczba; ++i)
    {
        lista_do_przodu.insert_after(lista_do_przodu.before_begin(), i);
    }
    skoncz_i_wypisz_roznice(czas, "Lista do przodu: ");

    czas = zacznij_mierzyc();
    for (int i = 0; i < liczba; ++i)
    {
        mapa.insert(make_pair(i, i));
    }
    skoncz_i_wypisz_roznice(czas, "Mapa: ");

    czas = zacznij_mierzyc();
    for (int i = 0; i < liczba; ++i)
    {
        zbior.insert(i);
    }
    skoncz_i_wypisz_roznice(czas, "Zbior: ");

    czas = zacznij_mierzyc();
    for (int i = 0; i < liczba; ++i)
    {
        nieuporz_mapa.insert(make_pair(i, i));
    }
    skoncz_i_wypisz_roznice(czas, "Nieuporzadkowana mapa: ");

    czas = zacznij_mierzyc();
    for (int i = 0; i < liczba; ++i)
    {
        nieuporz_zbior.insert(i);
    }
    skoncz_i_wypisz_roznice(czas, "Nieuporzadkowany zbior: ");
}
//*****************************************************************************************************************************************************************************************
void sortowanie()
{
    cout << "\tSortowanie:\n";

    auto czas = zacznij_mierzyc();
    sort(wektor.begin(), wektor.end());
    skoncz_i_wypisz_roznice(czas, "Vector: ");

    czas = zacznij_mierzyc();
    sort(kolejka.begin(), kolejka.end());
    skoncz_i_wypisz_roznice(czas, "Kolejka: ");

    czas = zacznij_mierzyc();
    lista.sort();
    skoncz_i_wypisz_roznice(czas, "Lista: ");

    czas = zacznij_mierzyc();
    lista_do_przodu.sort();
    skoncz_i_wypisz_roznice(czas, "Lista do przodu: ");

    czas = zacznij_mierzyc();
    skoncz_i_wypisz_roznice(czas, "Mapa: ");

    czas = zacznij_mierzyc();
    skoncz_i_wypisz_roznice(czas, "Zbior: ");

    czas = zacznij_mierzyc();
    skoncz_i_wypisz_roznice(czas, "Nieuporzadkowana mapa: ");

    czas = zacznij_mierzyc();
    skoncz_i_wypisz_roznice(czas, "Nieuporzadkowany zbior: ");
}

//*****************************************************************************************************************************************************************************************
void wkladanie_liczb(tryb_wkladania tryb)
{
    cout << "\tWkladanie:\n";

    cout << "Podaj ilosc wkladanych liczb: ";
    int ilosc;
    cin >> ilosc;

    if(tryb == tryb_wkladania::poczatek)
    {
        auto czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            wektor.insert(wektor.begin(), i);
        }
        skoncz_i_wypisz_roznice(czas, "Vector: ");

        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            kolejka.push_front(i);
        }
        skoncz_i_wypisz_roznice(czas, "Kolejka: ");

        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            lista.push_front(i);
        }
        skoncz_i_wypisz_roznice(czas, "Lista: ");

        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            lista_do_przodu.push_front(i);
        }
        skoncz_i_wypisz_roznice(czas, "Lista do przodu: ");

        cout << "UWAGA: W MAPIE NIE MOZNA WLOZYC NA POCZATEK" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            mapa.insert(make_pair(i, i));
        }
        skoncz_i_wypisz_roznice(czas, "Vector: ");

        cout << "UWAGA: W ZBIORZE NIE MOZNA WLOZYC NA POCZATEK" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            zbior.insert(i);
        }
        skoncz_i_wypisz_roznice(czas, "Zbior: ");

        cout << "UWAGA: W NIEUPORZADKOWANEJ MAPIE NIE MOZNA WLOZYC NA POCZATEK" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            nieuporz_mapa.insert(make_pair(i, i));
        }
        skoncz_i_wypisz_roznice(czas, "Nieuporzadkowana mapa: ");

        cout << "UWAGA: W NIEUPORZADKOWANYM ZBIORZE NIE MOZNA WLOZYC NA POCZATEK" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            nieuporz_zbior.insert(i);
        }
        skoncz_i_wypisz_roznice(czas, "Nieuporzadkowany zbior: ");
    } else if (tryb == tryb_wkladania::koniec)
    {
        auto czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            wektor.push_back(i);
        }
        skoncz_i_wypisz_roznice(czas, "Vector: ");

        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            kolejka.push_back(i);
        }
        skoncz_i_wypisz_roznice(czas, "Kolejka: ");

        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            lista.push_back(i);
        }
        skoncz_i_wypisz_roznice(czas, "Lista: ");

        czas = zacznij_mierzyc();
        auto before_end = lista_do_przodu.before_begin();
        for (auto &_ : lista_do_przodu)
            ++before_end;
        for (int i = 0; i < ilosc; ++i)
        {
            lista_do_przodu.insert_after(before_end, i);
        }
        skoncz_i_wypisz_roznice(czas, "Lista do przodu: ");

        cout << "UWAGA: W MAPIE NIE MOZNA WLOZYC NA KONIEC" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            mapa.insert(make_pair(i, i));
        }
        skoncz_i_wypisz_roznice(czas, "Mapa: ");

        cout << "UWAGA: W ZBIORZE NIE MOZNA WLOZYC NA KONIEC" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            zbior.insert(i);
        }
        skoncz_i_wypisz_roznice(czas, "Zbior: ");

        cout << "UWAGA: W NIEUPORZADKOWANEJ MAPIE NIE MOZNA WLOZYC NA KONIEC" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            nieuporz_mapa.insert(make_pair(i, i));
        }
        skoncz_i_wypisz_roznice(czas, "Nieuporzadkowana mapa: ");

        cout << "UWAGA: W NIEUPORZADKOWANYM ZBIORZE NIE MOZNA WLOZYC NA KONIEC" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            nieuporz_zbior.insert(i);
        }
        skoncz_i_wypisz_roznice(czas, "Nieuporzadkowany zbior: ");
    } else 
    {
        auto czas = zacznij_mierzyc();
        auto gdzie_w = wektor.begin() + wektor.size() / 2;
        for (int i = 0; i < ilosc; ++i)
        {
            wektor.insert(gdzie_w, i);
        }
        skoncz_i_wypisz_roznice(czas, "Vector: ");

        czas = zacznij_mierzyc();
        auto gdzie_k = kolejka.begin() + kolejka.size() / 2;
        for (int i = 0; i < ilosc; ++i)
        {
            kolejka.insert(gdzie_k, i);
        }
        skoncz_i_wypisz_roznice(czas, "Kolejka: ");

        czas = zacznij_mierzyc();
        auto gdzie_l = lista.begin();
        for (int i = 0; i < lista.size() / 2; ++i, ++gdzie_l) {}
            for (int i = 0; i < ilosc; ++i)
            {
            lista.insert(gdzie_l, i);
            }
        skoncz_i_wypisz_roznice(czas, "Lista: ");

        czas = zacznij_mierzyc();
        int miejsce_l_f = distance(lista_do_przodu.begin(), lista_do_przodu.end());
        auto gdzie_l_f = lista_do_przodu.begin();
        for (int i = 0; i < miejsce_l_f / 2; ++i, ++gdzie_l_f) {}
        for (int i = 0; i < ilosc; ++i)
        {
            lista_do_przodu.insert_after(gdzie_l_f, i);
        }
        skoncz_i_wypisz_roznice(czas, "Lista do przodu: ");

        cout << "UWAGA: W MAPIE NIE MOZNA WLOZYC NA SRODEK" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            mapa.insert(make_pair(i, i));
        }
        skoncz_i_wypisz_roznice(czas, "Mapa: ");

        cout << "UWAGA: W ZBIORZE NIE MOZNA WLOZYC NA SRODEK" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            zbior.insert(i);
        }
        skoncz_i_wypisz_roznice(czas, "Zbior: ");

        cout << "UWAGA: W NIEUPORZADKOWANEJ MAPIE NIE MOZNA WLOZYC NA SRODEK" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            nieuporz_mapa.insert(make_pair(i, i));
        }
        skoncz_i_wypisz_roznice(czas, "Nieuporzadkowana mapa: ");

        cout << "UWAGA: W NIEUPORZADKOWANYM ZBIORZE NIE MOZNA WLOZYC NA SRODEK" << endl;
        czas = zacznij_mierzyc();
        for (int i = 0; i < ilosc; ++i)
        {
            nieuporz_zbior.insert(i);
        }
        skoncz_i_wypisz_roznice(czas, "Nieuporzadkowany zbior: ");
    }
}

//*****************************************************************************************************************************************************************************************
void usuwanie()
{
    cout << "Podaj ilosc elementow do usuniecia: ";
    int ilosc;
    cin >> ilosc;

    auto czas = zacznij_mierzyc();
    wektor.erase(wektor.begin(), wektor.begin() + ilosc);
    skoncz_i_wypisz_roznice(czas, "Vector: ");

    czas = zacznij_mierzyc();
    kolejka.erase(kolejka.begin(), kolejka.begin() + ilosc);
    skoncz_i_wypisz_roznice(czas, "Kolejka: ");

    czas = zacznij_mierzyc();
    auto lista_wsk = lista.begin();
    for (int i = 0; i < ilosc; ++i)
    {
        lista_wsk++;
    }
        lista.erase(lista.begin(), lista_wsk);
    skoncz_i_wypisz_roznice(czas, "Lista: ");

    czas = zacznij_mierzyc();
    auto lista_f_wsk = lista_do_przodu.begin();
    for (int i = 0; i < ilosc; ++i)
    {
        lista_f_wsk++;
    }
    lista_do_przodu.erase_after(lista_do_przodu.before_begin(), lista_f_wsk);
    skoncz_i_wypisz_roznice(czas, "Lista do przodu: ");

    czas = zacznij_mierzyc();
    auto mapa_wsk = mapa.begin();
    for (int i = 0; i < ilosc; ++i)
    {
        mapa_wsk++;
    }
    mapa.erase(mapa.begin(), mapa_wsk);
    skoncz_i_wypisz_roznice(czas, "Mapa: ");

    czas = zacznij_mierzyc();
    auto zbior_wsk = zbior.begin();
    for (int i = 0; i < ilosc; ++i)
    {
        zbior_wsk++;
    }
    zbior.erase(zbior.begin(), zbior_wsk);
    skoncz_i_wypisz_roznice(czas, "Zbior: ");

    czas = zacznij_mierzyc();
    auto mapa_n_wsk = nieuporz_mapa.begin();
    for (int i = 0; i < ilosc; ++i)
    {
        mapa_n_wsk++;
    }
    nieuporz_mapa.erase(nieuporz_mapa.begin(), mapa_n_wsk);
    skoncz_i_wypisz_roznice(czas, "Nieuporzadkowana mapa: ");

    czas = zacznij_mierzyc();
    auto zbior_n_wsk = nieuporz_zbior.begin();
    for (int i = 0; i < ilosc; ++i)
    {
        zbior_n_wsk++;
    }
    nieuporz_zbior.erase(nieuporz_zbior.begin(), zbior_n_wsk);
    skoncz_i_wypisz_roznice(czas, "Nieuporzadkowany zbior: ");
}

//*****************************************************************************************************************************************************************************************
int main()
{
    cout << "Wpisz ilosc elementow: ";
    int64_t liczba;
    cin >> liczba;

    uzupelnienie(liczba);

    while(true) {
        cout << "\nCo chcesz badac? 1 - sortowanie, 2 - wkladanie, 3 - usuwanie, 4 - koniec" << endl;
        int wpr;
        cin >> wpr;

        switch (wpr)
        {   
        case 1:
            sortowanie();
            break;
        case 2:
            cout << "1 - poczatek, 2 - srodek, 3 - koniec: ";
            cin >> wpr;
            tryb_wkladania jaki_tryb;
            if(wpr == 1)
                jaki_tryb = tryb_wkladania::poczatek;
            else if(wpr == 2)
                jaki_tryb = tryb_wkladania::srodek;
            else
                jaki_tryb = tryb_wkladania::koniec;

            wkladanie_liczb(jaki_tryb);
            break;
        case 3:
            usuwanie();
            break;
        case 4:
            return 0;
            break;

        default:
            break;
        }
    }
}