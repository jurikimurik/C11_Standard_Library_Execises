// Zadanie 3 - Podstawowe działania na liczbach zespolonych. Pozwól użytkownikowi na wpisanie dwóch liczb zespolonych. Następnie 
// pozwól mu wykonać działania na nich: dodawać, odejmować od siebie, mnożyć, dzielić. Pozwól również na obliczenie modułu, 
// kwadratu modułu i kat reprezentacji dla kazdej z liczb zespolonych.
#include <complex>
#include <cmath>
#include <array>
#include <iostream>
#include "../narzedzia.h"
using namespace std;

int main()
{
    using typ_licz_ur = long double;

    cout << "Kazda liczbe zespolona wprowadzaj w postaci (<liczba>, <urojona>)!" << endl;
    complex<typ_licz_ur> c1 = wprowadzenie<complex<typ_licz_ur>>("Wprowadz pierwsza liczbe zespolona: ");

    complex<typ_licz_ur> c2 = wprowadzenie<complex<typ_licz_ur>>("Wprowadz druga liczbe zespolona: ");

    while(true)
    {
        array tablica = {c1, c2};
        array<long double (*)(const complex<long double> &), 3> tablica_funkcje = {&abs<typ_licz_ur>, &norm<typ_licz_ur>, &arg<typ_licz_ur>};

        cout
            << "Pierwsza: " << c1 << "\nDruga: " << c2 << endl;
        cout << "\t1 - dodawanie, 2 - odejmowanie, 3 - mnozenie, 4 - dzielenie, 5 - modul, 6 - kwadrat modulu, 7 - kat, 8 - wyjscie." << endl;
        int odpowiedz = wprowadzenie<int>("Wybierz dzialanie: ");
        size_t odpowiedz_dwa = 0;
        switch (odpowiedz)
        {
        case 1:
            cout << "c1 + c2 = " << (c1 + c2) << endl;
            break;
        case 2:
            cout << "c1 - c2 = " << (c1 - c2) << endl;
            break;
        case 3:
            cout << "c1 * c2 = " << (c1 * c2) << endl;
            break;
        case 4:
            cout << "c1 / c2 = " << (c1 / c2) << endl;
            break;
        case 5 ... 7:
            odpowiedz_dwa = wprowadzenie<size_t>("Dla pierwszego - 1, dla drugiego - 2: ");
            if(odpowiedz_dwa < 3)
                cout << tablica_funkcje[odpowiedz - 5](tablica[odpowiedz_dwa - 1]) << endl;
            break;
        case 8:
            return EXIT_SUCCESS;
            break;

        default:
            break;
        }
        cout << endl
             << endl;
    }
}