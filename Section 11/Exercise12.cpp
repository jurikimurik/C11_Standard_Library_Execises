// Zadanie 12 - Zgadywanka. Gracz posiada dwa zgenerowane przez program ciagi. Musi stwierdzic czy sa takie same czy to jest jedynie 
// permutacja. Jezeli sa jednak tylko czesciowo dobre, musi podac pozycje na ktorej zaczynaja sie roznic. 10 rund, na koncu wyniki.
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <random>
using namespace std;
//************************************************************************************************************************************
using para_ciagow = pair<vector<int>, vector<int>>;
//************************************************************************************************************************************
para_ciagow generuj_ciagi()
{
    int ilosc_cyfr = 10;

    vector<int> ciag;
    vector<int> drugi;

    int opcja = rand() % 3;
    if (opcja == 0)
    {
        for (int i = 0; i < ilosc_cyfr; ++i)
        {
            ciag.push_back(rand() % ilosc_cyfr*2);
        }
        drugi = ciag;
    } else if(opcja == 1) {
        for (int i = 0; i < ilosc_cyfr; ++i)
        {
            ciag.push_back(rand() % ilosc_cyfr * 2);
        }

        drugi = ciag;
        shuffle(drugi.begin(), drugi.end(), mt19937());
    }
    else
    {
        int roznica_od = rand() % (ilosc_cyfr - ilosc_cyfr/2) + 5;
        for (int i = 0; i < roznica_od; ++i)
        {
            ciag.push_back(rand() % ilosc_cyfr * 2);
        }

        drugi = ciag;
        for (int i = 0; i < ilosc_cyfr - roznica_od; ++i)
        {
            ciag.push_back(rand() % ilosc_cyfr * 2);
            drugi.push_back(rand() % ilosc_cyfr * 2);
        }
    }

    return make_pair(ciag, drugi);
}
//************************************************************************************************************************************
void wypisz(para_ciagow::first_type ciag)
{
    for(const auto& elem : ciag)
    {
        cout << elem << ", ";
    }
    cout << endl;
}
//************************************************************************************************************************************
int runda()
{
    int wynik_dedukcji = 0;
    para_ciagow dwa_ciagi = generuj_ciagi();

    wypisz(dwa_ciagi.first);
    wypisz(dwa_ciagi.second);

    cout << "\n\nCiagi sa: 1 - takie same, 2 - jeden jest permutacja innego, 3 - czesciowo dobre: ";
    int odpowiedz;
    cin >> odpowiedz;

    if(odpowiedz == 1)
    {
        if(equal(dwa_ciagi.first.begin(), dwa_ciagi.first.end(), dwa_ciagi.second.begin()))
        {
            wynik_dedukcji += 50;
        }
    } else if (odpowiedz == 2) {
        if (is_permutation(dwa_ciagi.first.begin(), dwa_ciagi.first.end(), dwa_ciagi.second.begin()))
        {
            wynik_dedukcji += 100;
        }
    } else {
        cout << "Podaj pozycje od ktorej sie roznia: ";
        int pozycja = 0;
        cin >> pozycja;

        auto pos = mismatch(dwa_ciagi.first.begin(), dwa_ciagi.first.end(), dwa_ciagi.second.begin());

        if(distance(dwa_ciagi.first.begin(), pos.first)+1 == pozycja)
        {
            wynik_dedukcji += 75;
        }
    }
    return wynik_dedukcji;
}
//************************************************************************************************************************************
int main()
{
    srand(time(NULL));

    int calkowity_wynik = 0;

    int ilosc_rund = 5;
    while(ilosc_rund-- > 0)
    {
        int wynik = runda();
        if(wynik)
            cout << "Bardzo dobrze!" << endl;
        calkowity_wynik += wynik;
    }

    cout << "Masz taki wynik: " << calkowity_wynik << "!\n";
}