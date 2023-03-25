// Zadanie 4 - Zestaw super-działań matematycznych. Niech użytkownik wprowadzi liczbę, z która następnie będzie mógł robić 
// następujące: podnosić do potęgi, obliczać pierwiastek, logarytm, logarytm dziesiętny, sin, coś, tg, asin, ceil, floor, fabs.
#include <cmath>
#include <iostream>
#include <vector>
#include "../narzedzia.h"
using namespace std;

int main()
{
    using typ_l = long double;

    vector<typ_l (*)(typ_l)> tablica_funkcji = {&sqrt, &log, &log10, &sin, &cos, &tan, &asin, &ceil, &floor, &fabs};

    typ_l liczba = wprowadzenie<typ_l>("Wprowadz liczbe: ");

    while(true)
    {
        cout << liczba << endl;
        cout << "0 - do potegi, 1 - pierwiastek, 2 - logarytm, 3 - logarytm dziesietny, 4 - sin, 5 - cos, 6 - tg, 7 - asin, \n8 - zaokraglenie w gore, 9 - zaokraglenie w dol, 10 - wartosc bezwzgledna czesci dziesietnej, 11 - wyjsc" << endl;
        size_t odpowiedz = wprowadzenie<size_t>("Wybierz dzialanie: ");

        if(odpowiedz == 11)
            return EXIT_SUCCESS;

        typ_l wynik = liczba;
        if (odpowiedz == 0)
        {
            size_t do_potegi = wprowadzenie<size_t>("Do jakiej potegi: ");
            wynik = pow(liczba, do_potegi);
        } else if(odpowiedz <= tablica_funkcji.size()) {
            wynik = tablica_funkcji[odpowiedz-1](liczba);
        } else {
            cout << "Niepoprawnie!" << endl;
        }
        cout << "\tWYNIK: " << wynik << endl
             << endl;
    }
}