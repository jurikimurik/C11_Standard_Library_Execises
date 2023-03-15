// Zadanie 8 - Symbioza. Posiadasz dwie listy z losowymi liczbami o ilosci 10. Zrob tak, zeby polowa pierwszej listy znalazla sie w drugiej i odwrotnie. Nastpenie posortuj kazda z tych list i zrob
// unikatowa. Wynik wypisz na ekranie.
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
//********************************************************************************************************************************************************************************
void wypiszListy(list<int> p, list<int> d, string text = "") {
    cout << text << endl;
    cout << "\tlista 1:";
    for(const auto& elem : p)
    {
        cout << elem << ", ";
    }
    cout << endl
         << endl
         << "\tlista 2:";
    for(const auto& elem : d) {
        cout << elem << ", ";
    }
    cout << endl
         << endl;
}
//********************************************************************************************************************************************************************************
int main()
{
    list<int> pierwsza;
    list<int> druga;

    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        pierwsza.push_back(rand() % 20);
        druga.push_back(rand() % 20);
    }

    wypiszListy(pierwsza, druga, "Przed: ");

    auto pos1 = pierwsza.begin();
    for (int i = 0; i < pierwsza.size() / 2; ++i)
    {
        pos1++;
    }

    swap_ranges(pierwsza.begin(), pos1, druga.begin());
    wypiszListy(pierwsza, druga, "Po swap: ");

    pierwsza.sort();
    pierwsza.unique();

    druga.sort();
    druga.unique();

    wypiszListy(pierwsza, druga, "Po sortowaniu i unikatowosci : ");
}