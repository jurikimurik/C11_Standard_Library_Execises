// Zadanie 17 - Calkowita mieszanina. Masz do dyspozycji vector<int> z losowymi liczbami od 0 do 1000 o ilosci 500. Za pomoca obiektow funkcyjnych z biblioteki STL musisz najpierw posortowac te liczby od
// najwiekszej do najmniejszej. Nastepnie usunac z niego krotnosci 2 kazda pozostala liczbe pomnozyc razy 22.
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;
using namespace std::placeholders;
//***************************************************************************************************************************************************************************
using kontener = vector<int>;
//***************************************************************************************************************************************************************************
void wypisz(kontener poj) {
    for(const auto & elem : poj) {
        cout << elem << ",";
    }
    cout << "\n\n\n";
}

//***************************************************************************************************************************************************************************
int main()
{
    kontener liczby_los;
    srand(time(NULL));

    for (int i = 0; i < 500; ++i)
    {
        liczby_los.push_back(rand() % 1000);
    }
    cout << "Przed sortowaniem: ";
    wypisz(liczby_los);

    sort(liczby_los.begin(), liczby_los.end(), greater<int>());

    cout << "Po sortowaniu: ";
    wypisz(liczby_los);

    liczby_los.erase(remove_if(liczby_los.begin(), liczby_los.end(), bind(equal_to<int>(), bind(modulus<int>(), _1, 2), 0)), liczby_los.end());

    cout << "Po usunieciu: ";
    wypisz(liczby_los);

    transform(liczby_los.cbegin(), liczby_los.cend(), liczby_los.begin(), bind(multiplies<int>(), _1, 22));

    cout << "Po wymnozeniu przez 22: ";
    wypisz(liczby_los);
}