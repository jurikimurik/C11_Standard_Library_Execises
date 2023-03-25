// Zadanie 6 - Wyznacznik macierzy 3x3. Niech użytkownik wprowadzi wartości do macierzy 3x3. Następnie musisz policzyć wyznacznik
// tej macierzy i podać użytkownikowi.
#include <valarray>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../narzedzia.h"
using namespace std;

template <typename T>
void macierz3D(const valarray<T> &macierz, int rozmiar_x = 0, int rozmiar_y = 0)
{
    auto *wsk = &macierz[0];
    if(rozmiar_x == 0 || rozmiar_y == 0)
    {
        rozmiar_x = sqrt(macierz.size());
        rozmiar_y = sqrt(macierz.size());
    }

    for (int y = 0; y < rozmiar_y; ++y)
    {
        for (int x = 0; x < rozmiar_x; ++x)
        {
            cout << *wsk++ << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    using VA = valarray<long double>;
    size_t rozmiar = 3;

    VA mac(rozmiar * rozmiar);

    cout << "Wypelnij macierz (lewo -> prawo): ";
    for (auto &elem : mac)
    {
        cin >> elem;
    }

    cout << "Liczymy wyznacznik tej macierzy: " << endl;
    macierz3D(mac);

    // przerabiamy na nowa macierz
    VA mod_mac(rozmiar * rozmiar + rozmiar * 2);

    auto *wsk = &mod_mac[0];
    auto *wsk_g = &mac[0];
    for (int y = 0; y < rozmiar; ++y)
    {
        for (int x = 1; x <= rozmiar; ++x)
        {
            *wsk++ = *wsk_g++;
        }
        advance(wsk_g, -3);
        for (int x = 1; x < rozmiar; ++x)
        {
            *wsk++ = *wsk_g++;
        }
        advance(wsk_g, 1);
    }

    //tniemy na potrzebne pod-zbiory
    vector<VA> potrzebne_rzady;
    for (int index = 0, odstep = 6, ilosc = 0; ilosc < 6; ilosc++)
    {
        potrzebne_rzady.push_back(VA(mod_mac[slice(index, 3, odstep)]));
        index++;

        if(index == 3) {
            index = 10;
            odstep = -4;
        }
    }

    // laczymy w zbiorach wszystko
    long double wyznacznik = 0;
    for (int i = 0; i < 6; ++i)
    {
        long double odp = accumulate(&potrzebne_rzady[i][0], &potrzebne_rzady[i][3], 1, multiplies<long double>());

        if(i < 3)
            wyznacznik += odp;
        else
            wyznacznik += (-1) * odp;
    }

    cout << "Wyznacznik: " << wyznacznik << endl;
}