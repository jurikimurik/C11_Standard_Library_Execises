#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
using namespace std;
//************************************************************************************************************
template <typename T>
inline T wprowadzenie(string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//************************************************************************************************************
template <>
inline string wprowadzenie(string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);
    return zmienna;
}
//***********************************************************************************************
#endif