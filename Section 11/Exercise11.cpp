// Zadanie 11 - Analizator zgenerowanych hasel. Niech program zgeneruje haslo. Nastenie wypisze wszystkie powtarzajace sie elementy pod
// rzad a na koniec niech znajdzie kazde wystapienie elementu podanego przez uzytkownika i wypisze ich pozycje.
#include <iostream>
#include <algorithm>
using namespace std;
//******************************************************************************************************************************
string generuj_haslo()
{
    srand(time(NULL));

    int dlugosc = 20;
    string haslo;

    for (int i = 0; i < dlugosc; ++i)
    {
        char znak = static_cast<char>(rand() % 126 - 33 + 33);
        haslo.push_back(znak);
    }

    return haslo;
}
//******************************************************************************************************************************
int main()
{
    string haslo = generuj_haslo();

    cout << haslo << endl;

    auto pos = adjacent_find(haslo.begin(), haslo.end());
    while(pos != haslo.end())
    {
        cout << "powtarzajace sie znaki pod rzad na pozycji " << distance(haslo.begin(), pos) + 1 << "." << endl;
        pos = adjacent_find(++pos, haslo.end());
    }

    cout << "Podaj element, ktory mam znalezc i wypisac jego pozycje: ";
    char element;
    cin >> element;

    pos = find(haslo.begin(), haslo.end(), element);
    while(pos != haslo.end())
    {
        cout << "Wystepuje na pozycji " << distance(haslo.begin(), pos) + 1 << "." << endl;
        pos = find(++pos, haslo.end(), element);
    }
}