// Zadanie 21 - Szkolne kryteria. Zostaje generowany określony ciąg liczb od 1 do 5. Następnie część która zdaje (według której oceny się 
// zdaje podaje użytkownik) zostaje zapisana w jednym zbiorze a druga część - w innym. Pokazana następnie jest ilość ludzi w jednym 
// zbiorze i w drugim.
//Shuffle
//Partition
//Partition copy
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> generuj_ciag()
{
    srand(time(NULL));
    vector<int> ciag;

    for (int ilosc = 0; ilosc < 90; ++ilosc)
    {
        ciag.push_back(rand() % 5 + 1);
    }

    return ciag;
}

int main()
{
    vector<int> ciag = generuj_ciag();

    cout << "Podaj ocene przy ktorej sie zdaje: ";
    int ocena;
    cin >> ocena;

    vector<int> dobry_ciag;
    vector<int> zly_ciag;

    partition_copy(ciag.begin(), ciag.end(), back_inserter(dobry_ciag), back_inserter(zly_ciag), [&ocena](int &liczba)
                   { return liczba >= ocena; });

    cout << "Ilosc porzadnych uczniow: " << dobry_ciag.size() << endl;

    cout << "Ilosc leniwcow: " << zly_ciag.size() << endl;
}