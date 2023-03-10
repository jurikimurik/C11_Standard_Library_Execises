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
    T ciag;
    cout << napis;
    while (cin)
    {
        T::value_type wpr = wprowadzenie<T::value_type>();
        ciag.push_back(wpr);
    }
    cin.clear();
    cin.ignore();
    ciag.pop_back();
}