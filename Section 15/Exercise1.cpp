// Zadanie 1 - W przeszlosci! Pobierz od użytkownika datę a następnie odejmij do tej daty 5 dni, 2 miesiace i jeden rok i wypisz ja na 
// ekranie.
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include "../narzedzia.h"
using namespace std;

int main()
{
    int dzien = wprowadzenie<int>("Wprowadz dzien: ");
    int miesiac = wprowadzenie<int>("Wprowadz miesiac: ");
    int rok = wprowadzenie<int>("Wprowadz rok: ");

    if (dzien - 5 < 1)
    {
        dzien = 1;
        miesiac--;
    } else {
        dzien -= 5;
    }

    if(miesiac-2 < 1)
    {
        miesiac = 1;
        rok--;
    } else {
        miesiac -= 2;
    }

    rok--;

    cout << dzien << "/" << miesiac << "/" << rok << endl;
}