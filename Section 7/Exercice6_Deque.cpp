// Zadanie 6 - Sprawdzenie wydajnosci vector i deque. Stworz oba pojemniki o ilosci elementow 50000 (uzupelnione wartosciami). Nastepnie zmierz czas, kiedy trzeba wstawiac do samego srodka wartosci
// porownaj te wartosci w przypadku vector i deque.
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <iostream>
using namespace std;
//****************************************************************************************************************************************************************************
int main()
{
    vector<int> wektor;
    deque<int> kolejka;

    int liczba = 50000;

    for (int i = 0; i < liczba; ++i)
    {
        wektor.push_back(i);
        kolejka.push_back(i);
    }

    auto czas = chrono::system_clock::now();
    for (int i = 0, middle = wektor.size() / 2; i < liczba; ++i)
    {
        wektor.insert(wektor.begin() + middle, i);
    }
    cout << "Dla wektora: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << endl;


    czas = chrono::system_clock::now();
    for (int i = 0, middle = kolejka.size() / 2; i < liczba; ++i)
    {
        kolejka.insert(kolejka.begin() + middle, i);
    }
    cout << "Dla deque: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << endl;
}