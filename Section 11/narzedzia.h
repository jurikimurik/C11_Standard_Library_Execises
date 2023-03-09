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