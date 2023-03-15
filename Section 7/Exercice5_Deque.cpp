// Zadanie 5 - Vector vs. Deque. Operujac na stworzonym wcześniej wektorze z 2000 liczbami i takim samym deque, sprawdz i wypisz roznice czasowe przy ktorych na sam poczatek wpiszesz do kadzego z nich
// liczby od 1 do 200000.

#include <vector>
#include <deque>
#include <ctime>
#include <chrono>
#include <iostream>
using namespace std;
//*******************************************************************************************************************************************************************************
int main()
{
    vector<int> wektor;
    deque<int> dekolejka;

    for (int i = 0; i < 2000; ++i) {
        wektor.push_back(i);
        dekolejka.push_back(i);
    }

    auto czas1 = std::chrono::system_clock::now();

    for (int i = 0; i < 200000; ++i)
    {
        wektor.insert(wektor.begin(), i);
    }

    auto dlugosc = std::chrono::system_clock::now() - czas1;
    cout << "Roznica w milisekundach: " << chrono::duration_cast<std::chrono::milliseconds>(dlugosc).count() << endl;

    czas1 = std::chrono::system_clock::now();
    for (int i = 0; i < 200000; ++i)
    {
        dekolejka.push_front(i);
    }

    dlugosc = std::chrono::system_clock::now() - czas1;
    cout << "Roznica w milisekundach: " << chrono::duration_cast<std::chrono::milliseconds>(dlugosc).count() << endl;
}