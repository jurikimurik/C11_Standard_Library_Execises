// Zadanie 7 - Ustawienia lokalnej narodowości. Ustaw strumien na wypisanie liczb naukowych. Następnie wypisz zwykły zbiór liczb 
// zmiennoprzecinkowych. Po czym wypisz go, używając obecnego obiektu typu locale.
#include <iostream>
#include <locale>
#include <vector>
#include "../narzedzia.h"
using namespace std;

int main()
{
    cout << scientific;

    vector<double> zbior_liczb = generuj_ciag_liczbowy<vector<double>>(0.34, 2.55, 20);

    for(const auto& elem : zbior_liczb)
    {
        cout << elem << ", ";
    }
    cout << endl << endl << endl;

    // Polski obiekty typu locale
    cout.imbue(locale("pl_PL"));

    for (const auto &elem : zbior_liczb)
    {
        cout << elem << ", ";
    }
    cout << endl;
}