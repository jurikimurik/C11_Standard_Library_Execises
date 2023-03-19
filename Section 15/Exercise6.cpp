// Zadanie 6 - Eksperymenty ze strumieniem. Za pomocą manipulatorów ustaw strumien w następnej konfiguracji: wypełniacz(_), wyrównanie 
// po prawej, szerokość 16 oraz zapisywanie wartości w postaci naukowej. Następnie wypisz zbiór losowych liczb zmiennoprzecinkowych na 
// ekranie używając poprzednich ustawień.
#include <iostream>
#include <iomanip>
#include "../narzedzia.h"
using namespace std;

int main()
{
    cout << setfill('_') << right << setw(16) << scientific;

    vector<double> zbior_liczb = 
}