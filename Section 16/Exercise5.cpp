// Zadanie 5 - Konwertor. Niech użytkownik poda ilość pieniędzy w złotówkach. Następnie ta liczbę należy przekonwertować 
// na euro i wypisać zgodnie z formatem miedzynarodowym Niemieckim.
#include <locale>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double wsp = 0.21;

    cout.imbue(locale("pl_PL"));
    cin.imbue(locale("pl_PL"));

    cout << showbase << fixed;

    long double pieniadze;
    cout << "Wprowadz ilosc pieniedzy w zlotowkach: ";
    cin >> get_money(pieniadze);

    cout.imbue(locale("de_DE"));
    cout << "Ilosc pieniedzy w euro: " << put_money(pieniadze * wsp, true) << endl;
}