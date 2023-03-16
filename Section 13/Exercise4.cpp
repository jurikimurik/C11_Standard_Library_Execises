// Zadanie 4 - Fala. Uzytkownik poda slowo, z ktorym nastepnie program zrobi krotka animacje typu fala (litery sie powiekszaja i 
// zmniejszaja).

#include "narzedzia.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    string slowo = wprowadzenie<string>("Wprowadz slowo:");

    auto odstep = chrono::milliseconds(50);
    string::iterator wsk = slowo.begin();
    do {
        *wsk = toupper(*wsk);
        cout << slowo << '\r' << flush;

        
        this_thread::sleep_for(odstep);
        wsk++;
    } while (wsk != slowo.end());

    wsk = slowo.begin();
    do {
        *wsk = tolower(*wsk);
        cout << slowo << '\r' << flush;

        
        this_thread::sleep_for(odstep);
        wsk++;
    } while (wsk != slowo.end());
}