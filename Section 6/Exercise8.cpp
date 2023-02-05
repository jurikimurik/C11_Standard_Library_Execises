// Zadanie 8 - Wstawianie. Niech uzytkownik wprowadzi ciag danych. Nastepnie wypisz go na ekranie i spytaj sie uzytkownika czy chce juz skonczyc dzialanie, czy moze dolaczyc jakis element.
// Jezeli wybiera to drugie, niech ponownie wprowadzi liczby i wypisz ponownie. Powtarzaj program w kolko, poki uzytkownik nie zechce wyjsc z programu.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//************************************************************************************************************************************************************************

void pokaz_ciag(vector<int> liczby) {
    cout << endl
         << endl
         << "Ciag: ";
    for (const auto &elem : liczby)
    {
        cout << elem << ' ';
    }
    cout << endl;
}

void wstaw(vector<int>& liczby) {
    cout << "Podaj pozycje: ";
    int element;
    cin >> element;
    element--;

    vector<int> inne_liczby;

    while (true)
    {
        cout << "Wprowadz element: ";
        int liczba;
        cin >> liczba;
        if (!cin)
            break;
        inne_liczby.push_back(liczba);
    }
    cin.clear();
    cin.ignore();

    copy(inne_liczby.cbegin(), inne_liczby.cend(), inserter(liczby, liczby.begin()+element));
}

int main()
{
    vector<int> liczby;
    while(true) {
        cout << "Wprowadz element: ";
        int liczba;
        cin >> liczba;
        if(!cin)
            break;
        liczby.push_back(liczba);
    }
    cin.clear();
    cin.ignore();

    bool dzialania = true;
    while (dzialania)
    {
        pokaz_ciag(liczby);
        cout << "Czy chcesz skończyć czy moze chcesz wstawic cos? 1 - wstawic, 2 - skonczyc ";
        int odp;
        cin >> odp;
        switch (odp)
        {
        case 1:
            wstaw(liczby);
            break;
        case 2:
            dzialania = false;
            break;

        default:
            cout << "Powtorz." << endl;
            break;
        }
    }
}