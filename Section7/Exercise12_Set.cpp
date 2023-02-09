// Zadanie 12 - Modulo 2. Stworz szablon, ktory bedzie typem kryterium sortowania. Zdefinuj w nim takie zachowanie, zeby na poczatku mial liczby podzielne przez 2, a na koncu nie. Udostepnij tryb pracy
// odwrotnej rowniez. Nastepnie stworz dwa kontenery set z roznymi ustawieniami trybu sortowania, ale wspolnym typem sortowania (stworzonym przez ciebie). Uzupelnij ich liczbami i sprawdz czy dobrze
// sortuja. Nastepnie przypisz do pierwszego konteneru drugi i sprawdz, co się stało, wypisując na ekranie rezultat.
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Sortownik {
public:

    enum tryb
    {
        normalny,
        odwrotny
    };

private: 
    tryb wybor;

public:
    Sortownik(tryb jaki_tryb = normalny) : wybor(jaki_tryb){}

    bool operator () (const int& l1, const int& l2) const {
        return wybor == normalny ? l1 % 2 == 0 || l2 % 2 == 1 : l2 % 2 == 0 || l1 % 2 == 1;
    }
};

int main()
{
    set<int, Sortownik> liczby1 = {1, 5, 4, 3, 7, 6, 8, 2, 9, 10};

    Sortownik reverse_order(Sortownik::odwrotny);
    set<int, Sortownik> liczby2(reverse_order);
    liczby2 = {1, 5, 4, 3, 7, 6, 8, 2, 9, 10};

    cout << "Liczby 1: ";
    for (const auto &elem : liczby1)
    {
        cout << elem << ", ";
    }
    cout << endl;

    cout << "Liczby 2: ";
    for (const auto &elem : liczby2)
    {
        cout << elem << ", ";
    }
    cout << endl;

    liczby1 = liczby2;
    cout << "Po przypisaniu - liczby 1: ";
    for (const auto &elem : liczby1)
    {
        cout << elem << ", ";
    }
    cout << endl;
}