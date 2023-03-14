// Zadanie 6 - Rózny rodzaj liczb. Niech użytkownik najpierw wybierze w jakim trybie wprowadza liczbę (01/8/10/16). Następnie program 
// przerobi to na liczbę zwykła i wypisze na ekranie.
#include <algorithm>
#include <iostream>
#include <string>
#include "narzedzia.h"
using namespace std;

int main()
{
    int podstawa = 0;
    while (podstawa == 0)
    {
        int rodzaj = wprowadzenie<int>("Rodzaj liczby: 1 - zero-jedynkowa, 2 - osemkowa, 3 - dziesietna, 4 - szesnastkowa: ");

        switch (rodzaj)
        {
        case 1:
            podstawa = 2;
            break;
        case 2:
            podstawa = 8;
            break;
        case 3:
            podstawa = 10;
            break;
        case 4:
            podstawa = 16;
            break;

        default:
            break;
        }
    }

    string liczba = wprowadzenie<string>("Wprowadz liczbe: ");
    cout << "Twoja liczba przy podstawie " << podstawa << " - to: " << stoll(liczba, nullptr, podstawa) << endl;
}