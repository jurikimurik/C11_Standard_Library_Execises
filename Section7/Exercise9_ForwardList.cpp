// Zadanie 9 - Zabawa w poszukiwacza. Posiadasz forward_list o pojemnosci 100. Twoim zadaniem jest znalezc kazda liczbe podzielna przez 2 i przed nia wpisac liczbe 99.
#include <forward_list>
#include <algorithm>
#include <iostream>
using namespace std;
//************************************************************************************************************************************************************************************
int main()
{
    forward_list<int> lista;
    for (int i = 0; i < 100; ++i) {
        lista.push_front(i);
    }

    for(auto& elem : lista) {
        cout << elem << ", ";
    }
    cout << endl
         << endl;

    auto pos1 = lista.begin();
    auto pos2 = lista.before_begin();

    for (int i = 0; i < 100; ++i, pos1++, pos2++) {
        if(*pos1 % 2 == 0) {
            lista.insert_after(pos2, 99);
            pos2++;
        }
    }

    for (auto &elem : lista)
    {
        cout << elem << ", ";
    }
    cout << endl
         << endl;
}