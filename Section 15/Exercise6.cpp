// Zadanie 6 - Eksperymenty ze strumieniem. Za pomocą manipulatorów ustaw strumien w następnej konfiguracji: wypełniacz(_), wyrównanie 
// po prawej, szerokość 16 oraz zapisywanie wartości w postaci naukowej. Następnie wypisz zbiór losowych liczb zmiennoprzecinkowych na 
// ekranie używając poprzednich ustawień.
#include <iostream>
#include <iomanip>
#include <vector>
#include "../narzedzia.h"
using namespace std;

int main()
{
    

    vector<double> zbior_liczb = {1.2424, 3.3412, 23.4232, 53.343};

    for(const auto& elem : zbior_liczb)
    {
        cout << setfill('_') << right << setw(16) << scientific << elem << ", ";
    }
}