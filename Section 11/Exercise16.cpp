// Zadanie 16 - Deszyfrator. Posiadasz słowo, w którym określone litery zostały zastapione innymi oraz zmieniła się ich kolejność. 
// Poskładaj słowo z powrotem w jak najmniejszej ilości kroków.
#include <utility>
#include <iostream>
using namespace std;
//**************************************************************************************************************
template <typename T>
auto wprowadzenie(string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//**************************************************************************************************************
auto daj_zaszyfrowane_slowo(string slowo_do_szyf)
{   
    const string praw_slowo = slowo_do_szyf;

    int losowosc = rand() % 3;
    if (losowosc == 0 || losowosc == 2)
    {
        auto od = slowo_do_szyf.begin() + rand() % slowo_do_szyf.size() / 3;
        auto az_do = od + rand() % 3;
        auto z = slowo_do_szyf.end() - rand() % slowo_do_szyf.size() / 3 - 1;

        swap_ranges(od, az_do, z);
    }
    if(losowosc == 1 || losowosc == 2)
    {
        char znak = slowo_do_szyf.at(rand() % slowo_do_szyf.size());
        char losowy_znak = static_cast<char>(rand() % 25 + 65);
        replace(slowo_do_szyf.begin(), slowo_do_szyf.end(), znak, losowy_znak);
    }


    return make_pair(praw_slowo, slowo_do_szyf);
}
//**************************************************************************************************************
void zamien_litere(string& probka)
{
    cout << "Wpisz litere, jaka chcesz wymienic: ";
    char stary_znak;
    cin >> stary_znak;

    cout << "Wpisz litere, NA jaka chcesz wymienic: ";
    char nowy_znak;
    cin >> nowy_znak;

    replace(probka.begin(), probka.end(), stary_znak, nowy_znak);
}
//**************************************************************************************************************
void przestaw_zakresy(string& probka)
{
    int od = wprowadzenie<int>("Podaj od jakiego indeksu: ");
    int az_do = wprowadzenie<int>("Az do jakiego indeksu: ");
    int z = wprowadzenie<int>("Od jakiego indeksu wymienic: ");

    if(z >= az_do && z >= od)
    {
        swap_ranges(probka.begin() + od, probka.begin() + az_do, probka.begin() + z);
    }
    else
    {
        cout << "Zle podany zakres" << endl;
    }
}
//**************************************************************************************************************
void wypisz_wynik(int ilosc_rund, bool czy_wygrana)
{
    if(czy_wygrana) {
        cout << "Wygrales! Zajelo ci to " << ilosc_rund << " rundy! Gratulacje!" << endl;
    } else {
        cout << "Niestety nie zwazajac na proby, przegrales. Tyle rund ci to zajelo: " << ilosc_rund << endl;
    }
}
//**************************************************************************************************************
int main()
{
    srand(time(NULL));

    pair<const string, const string> para_slow = daj_zaszyfrowane_slowo("Polsko Japonska");

    int ilosc_rund = 0;
    bool wygrana = false;
    string probka = para_slow.second;
    bool dzialania = true;
    while (dzialania)
    {
        cout << "Slowo: " << probka << endl;

        cout << "1 - zamien wszystkie okreslone litery jedna, 2 - przestaw zakres, 3 - zatwierdz" << endl;
        int odpowiedz = wprowadzenie<int>("Wybierz dzialanie: ");

        switch (odpowiedz)
        {
        case 1:
            zamien_litere(probka);
            break;
        
        case 2:
            przestaw_zakresy(probka);
            break;

        case 3:
            if(para_slow.first == probka)
                wygrana = true;
            dzialania = false;
            break;

        default:
            break;
        }

        ilosc_rund++;
    }

    wypisz_wynik(ilosc_rund, wygrana);
}