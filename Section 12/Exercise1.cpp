// Zadanie 1 - Stos ksiazek. Posiadasz zestaw ksiazek. Wrzuc ich na stos a nastepnie odczytaj po kolei i wypisz na ekranie.
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<string> ksiazki = {"Pan Lodowego Ogrodu", "Sztywny", "Hobbit", "Miecz przeznaczenia", "Ostatnie zyczenie"};

    stack<string> stos_ksiazek;
    for(auto& elem : ksiazki)
    {
        stos_ksiazek.push(move(elem));
    }

    while(!stos_ksiazek.empty())
    {
        cout << stos_ksiazek.top() << ", ";
        stos_ksiazek.pop();
    }
}