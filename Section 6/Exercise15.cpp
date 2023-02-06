// Zadanie 15 - Dwojki i jedynki. Korzystajac z lambdy w algorymie sortujacym, posortuj wszystko tak, by liczby podzielne przez 2 byly na samym poczatku, a inne - na samym koncu.
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//***************************************************************************************************************************************************************************************
int main()
{
    vector<int> liczby = {1,2,3,4,5,6};

    sort(liczby.begin(), liczby.end(), [](int a, int b)
         { return (a % 2 == 0); });

    for(auto & elem : liczby) {
        cout << elem << ", ";
    }
    cout << endl;
}