// Zadanie 4 - Sprawdzanie wydajnosci V.2. Masz dwa wektory typu int. Dla jednego z nich zarezerwuj obszar pamięci potrzebny na 20000000 liczb. Nastepnie musisz do kazdego wektoru przypisac po kolei liczby od
// 0 do 20000000, przy czym sprawdzic czas, jaki potrzebny jest do przeprowadzenia tej operacji dla pierwszego vectoru oraz drugiego, a nastepnie te roznicy wypisac i pokazac uzytkownikowi.
#include <vector>
#include <chrono>
#include <iostream>
using namespace std;
//****************************************************************************************************************************************************************************************************************
int main()
{
    vector<int> rezerwa;
    rezerwa.reserve(20000000);

    vector<int>
        na_biezaco;

    auto czas = chrono::system_clock::now();
    for (int i = 0; i < 20000000; ++i) {
        na_biezaco.push_back(i);
    }
    cout << "Kiedy rezerwujemy na biezaco, to potrzeba nam tyle milisekund: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << endl;

    czas = chrono::system_clock::now();
    for (int i = 0; i < 20000000; ++i)
    {
        rezerwa.push_back(i);
    }
    cout << "A jezeli zarezerwujemy wczesniej, to potrzeba nam jest tyle: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << endl;
}