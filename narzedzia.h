#ifndef NARZEDZIA_H
#define NARZEDZIA_H

#include <iostream>
#include <algorithm>
using namespace std;
//******************************************************************************************************************
template <typename T>
T wprowadzenie(string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//-------------------------------------
template <>
string wprowadzenie(string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);
    return zmienna;
}
//******************************************************************************************************************
template <typename T>
void drukuj(const T& tablica, string napis_przed = "", string napis_po = "")
{
    cout << napis_przed;
    for (typename T::value_type cos : tablica)
    {
        cout << cos << ", ";
    }
    cout << napis_po;
}
//******************************************************************************************************************
template <typename T>
T wprowadz_ciag(string napis = "")
{
    using typ = typename T::value_type;

    T ciag;
    cout << napis;
    while (cin)
    {
        typ wpr = wprowadzenie<typ>();
        ciag.push_back(wpr);
    }
    cin.clear();
    cin.ignore();
    ciag.pop_back();

    return ciag;
}
//******************************************************************************************************************
template <typename T>
T generuj_ciag_liczbowy(int od, int az_do, int ilosc)
{
    srand(time(NULL));
    using typ = typename T::value_type;

    T ciag;

    for (int i = 0; i < ilosc; ++i)
    {
        ciag.push_back(rand() % (az_do - od) + od);
    }

    return ciag;
}

#endif