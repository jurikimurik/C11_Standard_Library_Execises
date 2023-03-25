// Zadanie 5 - Podstawowe działania na macierzach. Niech użytkownik poda rozmiar dwóch kwadratowych macierzy, które 
// następnie uzupełni. Pozwól mu dodawać, odejmować, dzielić i mnożyć macierze pomiędzy sobą.
#include <valarray>
#include <iostream>
#include "../narzedzia.h"
using namespace std;

template <typename T>
void macierz3D(const valarray<T>& macierz)
{
    auto *wsk = &macierz[0];
    int rozmiar_kw = sqrt(macierz.size());

    for (int y = 0; y < rozmiar_kw; ++y)
    {
        for (int x = 0; x < rozmiar_kw; ++x)
        {
            cout << *wsk++ << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    size_t rozmiar = wprowadzenie<size_t>("Podaj rozmiar macierz (kwadratowych): ");

    valarray<long double> mac1(rozmiar * rozmiar), mac2(rozmiar * rozmiar);

    cout << "Wypelnij macierz pierwsza (lewo -> prawo): ";
    for (auto &elem : mac1)
    {
        cin >> elem;
    }

    cout << "Wypelnij macierz druga (lewo -> prawo): ";
    for (auto &elem : mac2)
    {
        cin >> elem;
    }

    while (true)
    {
        cout << "\nTwoje macierze: " << endl;
        macierz3D(mac1);
        macierz3D(mac2);

        cout << "\n1 - dodaj ich, 2 - odejmij, 3 - pomnoz, 4 - podziel, 5 - skoncz: " << endl;
        size_t odpowiedz = wprowadzenie<size_t>("Wybierz dzialanie: ");
        decltype(mac1) mac(rozmiar * rozmiar);
        switch (odpowiedz)
        {
        case 1:
            mac = mac1 + mac2;
            break;
        case 2:
            mac = mac1 - mac2;
            break;
        case 3:
            mac = mac1 * mac2;
            break;
        case 4:
            mac = mac1 / mac2;
            break;
        case 5:
            return EXIT_SUCCESS;
            break;
        default:
            break;
        }

        cout << "WYNIK: " << endl;
        macierz3D(mac);
    }
}