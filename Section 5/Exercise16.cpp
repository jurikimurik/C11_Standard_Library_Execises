// Zadanie 16. Stworz intializer list z nieuporzadkowanymi i losowymi (przez program lub przez ciebie liczbami typu int). Nastepnie za pomoca
// funkcji minmax() wypisz najwieksza i najmniejsza liczbe na ekranie

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//*****************************************************************************************************************************

int main()
{
    initializer_list<int> liczby = {23, 53, 12, 35, 755, 12, 0};
    pair maksimin = minmax(liczby);

    cout << "Minimalny = " << maksimin.first << ", Maksymalny = " << maksimin.second << endl;
}
