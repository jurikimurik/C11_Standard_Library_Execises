// Zadanie 1 - Rodzaje pieniężne. Stwórz obiekty lokalne odpowiadające językom: niemiecki, francuski, polski i japoński. Przypisz 
// te obiekty określonym strumieniom, którzy będą korzystać ze wspólnego strumienia cout. Następnie użytkownik wprowadzi określoną 
// kwotę pieniężną, która trzeba będzie przekonwertowana i wypisana w czterech różnych formatach za pomocą poprzednich strumieni.
#include <locale>
#include <iostream>
#include <iomanip>
#include "../narzedzia.h"
using namespace std;

int main()
{
    ostream ger(cout.rdbuf());
    ger.imbue(locale("de_DE"));
    ger << showbase;

    ostream fran(cout.rdbuf());
    fran.imbue(locale("fr_FR"));
    fran << showbase;

    ostream pol(cout.rdbuf());
    pol.imbue(locale("pl_PL"));
    pol << showbase;

    ostream jap(cout.rdbuf());
    jap.imbue(locale("ja_JP"));
    jap << showbase;

    long double liczba;
    cout << "Wprowadz liczbe (w PLN): ";
    cin.imbue(locale("pl_PL"));
    cin >> get_money(liczba, true);

    double wspolczynniki[] = {0.21, 0.21, 1, 30.48};
    double *wsk = &wspolczynniki[0];

    ger << "Niemiecka kwota: " << put_money(liczba * (*wsk++), true) << endl;
    fran << "Francuska kwota: " << put_money(liczba * (*wsk++), true) << endl;
    pol << "Polska kwota: " << put_money(liczba * (*wsk++), true) << endl;
    jap << "Japonska kwota: " << put_money(liczba * (*wsk++), true) << endl;
}