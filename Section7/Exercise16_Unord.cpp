// Zadanie 16 - Mieszanina. Za pomoca unordered_set zrob tak, zeby uzytkownik wprowadzil poczatkowe liczby, nastepnie pokaz to na ekranie. Pozniej niech uzytkownik wprowadzi kolejne liczby i sprawdzi, czy
// wartosci w unordered_set się pomieszały
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
//**********************************************************************************************************************************************************************************************
int main()
{
    unordered_set<int> liczby;

    cout << "Wprowadzaj liczby, a kiedy skonczysz - wpisz 'e'" << endl;
    while(true) {
        int liczba;
        cin >> liczba;
        if(!cin)
            break;
        else
            liczby.insert(liczba);
    }
    cin.clear();
    cin.ignore();

    cout << "\tMasz taki uklad: \n";
    for (const auto &elem : liczby)
    {
        cout << elem << ", ";
    }
    cout << endl;

    cout << "Wprowadzaj kolejne liczby, a kiedy skonczysz - wpisz 'e'" << endl;
    while (true)
    {
        int liczba;
        cin >> liczba;
        if (!cin)
            break;
        else
            liczby.insert(liczba);
    }

    cout << "\tA teraz masz taki uklad: \n";
    for (const auto &elem : liczby)
    {
        cout << elem << ", ";
    }
    cout << endl;
}