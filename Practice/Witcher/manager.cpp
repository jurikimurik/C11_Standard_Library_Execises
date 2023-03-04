#include "manager.h"
#include <chrono>
#include <thread>
using namespace std;
//***********************************************************************************************
void GameManager::wypisz_wynik_rzutu(const Player& gracz)
{
    cout << "Gracz " << gracz.daj_imie() << " wyrzucil: ";
    for(auto& elem : gracz.daj_koscie())
    {
        cout << elem << ", ";
    }
    cout << endl
         << "Jest to wynik: " << sprawdzac_wynikow.daj_nazwe_wyniku((gracz.daj_koscie())) << " - " << sprawdzac_wynikow.daj_wynik(gracz.daj_koscie());
    cout << endl;
}
//***********************************************************************************************
template <typename T>
T GameManager::wprowadzenie(const Text_Object& obj)
{
    ekran.wprowadzenie(obj);
    T zmienna = ::wprowadzenie<T>("");
    return zmienna;
}
//***********************************************************************************************
void GameManager::rozpocznij_gre()
{
    // Niech zyje losowosc!
    srand(time(NULL));

    ekran.odswiez();

    auto pos = ekran.get_coordinate_position(position::srodek);
    Label napis("ABCD\nabcde\ndio\nklj", pos.first, pos.second);

    cout << napis.daj_szerokosc(4) << endl;

    /*ekran + napis;

    int ilosc_graczy = wprowadzenie<int>(napis);

    while(ilosc_graczy-- > 0)
    {
        napis.ustaw_tekst("Wprowadz imie gracza: ");
        string imie = wprowadzenie<string>(napis);
        

        napis.ustaw_tekst("Wprowadz ilosc kosci: ");
        int ilosc_kosci = wprowadzenie<int>(napis);

        napis.ustaw_tekst("0 - Gracz, 1 - Komputer: ");
        bool czy_k = wprowadzenie<int>(napis);

        gracze.insert(gracze.end(), Player(imie, czy_k, ilosc_kosci));
    }

    ekran - napis;
    ekran.odswiez();*/

    //zacznij_kolejna_runde();

    
}
//***********************************************************************************************
void GameManager::ruch_komputera(Player& gracz)
{
    int wynik_komputera = sprawdzac_wynikow.daj_wynik(gracz.daj_koscie());
    bool czy_najwiekszy = true;
    for(const auto& elem : gracze)
    {
        if (wynik_komputera < sprawdzac_wynikow.daj_wynik(elem.daj_koscie()))
        {
            czy_najwiekszy = false;
            break;
        }
    }

    if(czy_najwiekszy)
    {
        return;
    } else {
        gracz.rzucz_kosci();
    }
   
}
//***********************************************************************************************
auto GameManager::daj_dzialania(Player &gracz)
{
    para_funkcjaGracza_opisFunkcji mozliwosci;

    mozliwosci.first.push_back(&Player::przerzut_okreslonych);
    mozliwosci.second.push_back("1 - Przerzut niektorych kosci");

    mozliwosci.first.push_back(&Player::pas);
    mozliwosci.second.push_back("2 - Pasowanie");

    return mozliwosci;
}
//***********************************************************************************************
void GameManager::wypisz_dzialania(para_funkcjaGracza_opisFunkcji para)
{
    for(const auto& elem : para.second)
    {
        cout << elem << ", ";
    }
    cout << endl;
}
//***********************************************************************************************
bool zrob_dzialanie(int odp, Player& gracz, para_funkcjaGracza_opisFunkcji& para)
{
    wskazniki_na_funkcje mozliwosci = para.first;
    auto wsk = mozliwosci.at(odp);

    (gracz.*wsk)();
    return true;
}
//***********************************************************************************************
void GameManager::ruch_gracza(Player& gracz)
{
    cout << "\n\tTeraz jest ruch: " << gracz.daj_imie() << "!" << endl;
    if (gracz.czy_jest_komputerem())
    {
        ruch_komputera(gracz);
        return;
    }

    auto mozl = daj_dzialania(gracz);
    wypisz_dzialania(mozl);

    auto pos = ekran.get_coordinate_position(position::srodek);
    Label napis("Wybierz dzialanie: ", pos.first, pos.second);
    ekran + napis;

    while(true)
    {
        int odpowiedz = wprowadzenie<int>(napis);
        if(zrob_dzialanie(--odpowiedz, gracz, mozl))
            break;
    }

    ekran - napis;

    cout << endl
         << endl;
}
//***********************************************************************************************
void GameManager::wyniki()
{
    cout << "\n\tWYNIKI: " << endl;

    multimap<int, Player*, greater<>> wygrana_kazdego;
    for (auto &elem : gracze)
    {
        wypisz_wynik_rzutu(elem);
        wygrana_kazdego.insert(make_pair(sprawdzac_wynikow.daj_wynik(elem.daj_koscie()), &elem));
    }

    auto pos = wygrana_kazdego.begin();

    cout << "Wygrywa: " << pos->second->daj_imie() << "!" << endl;
    pos->second->wygrana();
}
//***********************************************************************************************
void GameManager::koniec_i_zwyciezca(const Player& gracz)
{
    cout << "Calkowicie wygrywa " << gracz.daj_imie() << "! Kongratulacje!" << endl;
}
//***********************************************************************************************
void GameManager::zacznij_kolejna_runde()
{
    ilosc_rund++;

    //Label napis("Zaczynamy runde numer " + to_string(ilosc_rund) + "!", );

    cout << "\n\n\tZaczynamy runde numer " << ilosc_rund << "!" << endl;

    for(auto& elem : gracze)
    {
        elem.rzucz_kosci();
        wypisz_wynik_rzutu(elem);
    }

    for(auto& elem : gracze)
    {
        ruch_gracza(elem);
    }

    wyniki();

    for(const auto& elem : gracze)
    {
        if(ilosc_rund_do_wygranej == elem.daj_ilosc_wygranych())
        {
            koniec_i_zwyciezca(elem);
            return;
        }
    }

    zacznij_kolejna_runde();
}
