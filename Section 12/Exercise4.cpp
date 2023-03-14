// Zadanie 4 - Z ludzkiego na komputerowy! Pozwól użytkownikowi wprowadzać liczby zwykle, które program musi przerabiać na komputerowe
// liczby.
#include <bitset>
#include <iostream>
#include <numeric>
#include "narzedzia.h"
using namespace std;

int main()
{
    cout << "Wprowadz liczbe: ";
    long long liczba = wprowadzenie<long long>();
    if (liczba < 0)
        liczba *= -1;

    bitset<numeric_limits<long long>::digits> super_dluga_liczba(liczba);

    string liczba_tekstowo = super_dluga_liczba.to_string();
    string krotka_liczba_tekstowo = liczba_tekstowo.substr(liczba_tekstowo.find('1'));

    cout << "Liczba w jezyku komputerowym: " << krotka_liczba_tekstowo << endl;
}