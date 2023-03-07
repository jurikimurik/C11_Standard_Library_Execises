// Zadanie 17 - Wypelniacz. Posiadasz pusty list. Wypełnij 50 jego pozycji jedna liczba, a następne 50 - losowymi liczbami za pomocą 
// generate. Wypisz na ekranie ten list.
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
//*********************************************************************************************************************
void wypelnij(list<int>& lista)
{
    lista.resize(50);

    fill(lista.begin(), lista.end(), 5);

    lista.resize(lista.size() + 50);
    auto pos = lista.begin();
    advance(pos, 50);

    generate(pos, lista.end(), rand);
}
//*********************************************************************************************************************
int main()
{
    list<int> lista;
    wypelnij(lista);

    for(int liczba : lista)
    {
        cout << liczba << ", ";
    }
}