// Zadanie 2 - Wyszukiwacz dopasowań. Posiadasz ciąg danych w postaci XML z imionami jednych osób, gdzie w środku jest imię innej osoby.
// Przeszukaj ten ciąg i wypisz odpowiednio imię pierwszej osoby, które odpowiada drugiemu imieniu.
#include <regex>
#include <iostream>
using namespace std;

int main()
{
    string dane = "<Natalia>Maks</Natalia><Paulina>Yurii</Paulina>";

    regex reg("<(.*)>(.*)</\\1>");
    smatch m;

    sregex_iterator pos(dane.cbegin(), dane.cend(), reg);
    sregex_iterator end;
    for(; pos != end; ++pos)
    {
        cout << pos->str(1) << " = " << pos->str(2) << endl;
    }
    cout << endl;
}