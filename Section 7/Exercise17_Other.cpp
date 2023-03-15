// Zadanie 17 - Ultra-tablica. Korzystajac ze zwyklej tablicy, ktora miesci 20 losowych liczb, posortuj ja a nastepnie wypisz wartosci na ekranie. (wykorzystaj algorytmy)
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;
//********************************************************************************************************************************************************************************************

//********************************************************************************************************************************************************************************************
int main()
{
    int tablica[] = {9, 6, 7, 2, 19, 2, 5, 15, 1, 4, 14, 18, 14, 6, 10, 8, 1, 14, 9, 3};

    sort(begin(tablica), end(tablica));

    for (int i = 0; i < 20; ++i)
    {
        cout << tablica[i] << ", ";
    }
}