// Zadanie 14 - Słownik. Stworz słownik, do ktorego uzytkownik bedzie mogl wprowadzac slowa a na koniec wypisze mu wszystkie wprowadzone przez niego słowa w postaci posortowanej od litery A do Z lub 
// odwrotnie, jezeli bedzie tego chcial.
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
//*******************************************************************************************************************************************************************************
int main()
{
    multimap<char, string> slownik;

    cout << "Wprowadzaj slowo po kolei i koncz przyciskiem ENTER. Gdy skonczysz, wpisz litere q" << endl;
    while (true)
    {
        string slowo;
        cin >> slowo;

        if(slowo == "q")
            break;

        slownik.insert(make_pair(toupper(slowo.at(0)), slowo));
    }

    cout << "Sortowanie od A do Z - 1, Sortowanie od Z do A - 2" << endl;
    int liczba;
    cin >> liczba;
    if(liczba == 2)
    {
        multimap<char, string, greater<char>> slownik_odwrotny(slownik.begin(), slownik.end());
        for (const auto &elem : slownik_odwrotny)
        {
            cout << elem.first << " - " << elem.second << endl;
        }
        cout << endl;
    }
    else
    {
        for (const auto &elem : slownik)
        {
            cout << elem.first << " - " << elem.second << endl;
        }
        cout << endl;
    }
}