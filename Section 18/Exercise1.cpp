// Zadanie 1 - Sprawdzenie wydajności. Masz uzupełnić określone wektory milionem liczb losowych. Sprawdź czy szybciej to się 
// wykona po kolei lub przy asynchronicznym wywołaniu. Zmierz czas również.
#include <thread>
#include <future>
#include <vector>
#include <chrono>
#include <iostream>
#include "../narzedzia.h"
using namespace std;

void funkcja_wypelniajaca()
{
    vector<int> liczby_losowe = generuj_ciag_liczbowy<vector<int>>(0, 1000000, 1000000);
}

int main()
{
    int ilosc_w = 10;

    cout << "Generujemy " << ilosc_w << " wektory po kolei: " << endl
         << flush;

    auto czas_teraz = chrono::system_clock::now();
    int ilosc = ilosc_w;
    while(ilosc > 0)
    {
        funkcja_wypelniajaca();
        ilosc--;
    }
    cout << "Zajelo to: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas_teraz).count() << " milisekund" << endl;

    cout << "Zrobimy to asynchronicznie: " << endl;
    czas_teraz = chrono::system_clock::now();

    vector<future<void>> watki;
    for (int i = 0; i < ilosc_w; ++i)
    {
        watki.push_back(async(funkcja_wypelniajaca));
    }

    for(auto& elem : watki)
    {
        elem.get();
    }

    cout << "Zajelo to: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas_teraz).count() << " milisekund" << endl;
}