// Zadanie 1 - Generacja liczb zmiennoprzecinkowych o zadanej precyzji. Niech użytkownik poda zakres, ilość liczb oraz 
// precyzję generowanych liczb zmiennoprzecinkowych. Wygeneruj mu te liczby zmiennoprzecinkowe i wypisz ich na ekranie.
#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>
#include "../narzedzia.h"
using namespace std;

int main()
{
    size_t ilosc = wprowadzenie<size_t>("Wprowadz ilosc liczb: ");

    double zakres_od = wprowadzenie<double>("Wprowadz dolny zakes liczb: ");
    double zakres_do = wprowadzenie<double>("Wprowadz gorny zakres liczb: ");

    size_t precyzja = wprowadzenie<size_t>("Podaj prezycje liczb: ");

    default_random_engine dre(time(nullptr));
    uniform_real_distribution urd(zakres_od, zakres_do);

    cout << fixed << setprecision(precyzja);
    for (int i = 0; i < ilosc; ++i)
    {
        double liczba = urd(dre);
        // opcjonalne obcinanie niepotrzebnych liczb przy precyzji
        liczba = ceil(liczba*pow(10, precyzja))/pow(10,precyzja);
        cout << liczba << " ";
    }
}