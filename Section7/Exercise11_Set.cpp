// Zadanie 11 - Porownywanie wyszukiwania. Stworz vector<int> oraz set<int> z liczbami od 0 do 2000000. Wyszukaj w kazdym z nich okresloną liczbe i porwnaj czasowe wyniki dla vector oraz dla set.
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<int> wektor;
    set<int> zbior;

    int ilosc_liczb = 20000000;

    for (int i = 0; i < ilosc_liczb; ++i)
    {
        wektor.push_back(i);
        zbior.insert(i);
    }

    cout << "Podaj liczbe z zakresu 0 do 20000000:";
    int liczba;
    cin >> liczba;

    auto czas = chrono::system_clock::now();

    if(find(wektor.begin(), wektor.end(), liczba) != wektor.end()) {
        cout << "Element znaleziony!" << endl;
    }

    cout << "Czas dla wektoru: " << chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now() - czas).count() << endl;

    czas = chrono::system_clock::now();

    if (zbior.find(liczba) != zbior.end())
    {
        cout << "Element znaleziony!" << endl;
    }

    cout << "Czas dla set'u: " << chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now() - czas).count() << endl;
}