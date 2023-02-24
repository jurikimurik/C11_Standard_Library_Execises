#include "manager.h"
#include <iostream>
using namespace std;
//***********************************************************************************************
template <typename T>
T wprowadzenie(std::string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//***********************************************************************************************
template <>
string wprowadzenie(std::string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);
    return zmienna;
}
//***********************************************************************************************
void GameManager::rozpocznij_gre()
{
    // Niech zyje losowosc!
    srand(time(NULL));
}
