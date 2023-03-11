// Zadanie 29 - Iloczyn skalarny. Zostaje generowany ciąg liczb i wypisany na ekranie. Następnie należy obliczyć jego sumę skalarna i 
// wypisać na ekranie.
#include "narzedzia.h"
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    auto ciag = generuj_ciag_liczbowy<vector<int>>(0, 100, 20);

    drukuj(ciag, "", "\n");

    cout << "Iloczyn skalarny: " << inner_product(ciag.begin(), ciag.end(), ciag.begin(), 0);
    cout << endl;
}