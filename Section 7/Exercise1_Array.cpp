// Zadanie 1 - Tablica zmian. Masz podany kontener array<int, 5> z wartosciami {1, 2, 3, 4, 5}. Spytaj sie uzytkownika, czy chce zmienic tam jakies elementy. Jezeli tak, to pozwol mu na to, lub zakoncz
// wykonywanie programu. Przetestuj dzialanie programu jezeli wprowadzisz za duzo liczb rowniez.
#include <array>
#include <algorithm>
#include <iostream>
using namespace std;
//********************************************************************************************************************************************
array<int, 5> zbior = {1, 2, 3, 4, 5};
//********************************************************************************************************************************************
void wypisz(array<int, 5>& zb) {
    for(const auto& elem : zb) {
        cout << elem << ", ";
    }
    cout << endl;
}
//********************************************************************************************************************************************
void zmiana(array<int, 5>& zb) {
    cout << "Podaj indeks 1: ";
    int index1;
    cin >> index1;
    index1--;
    if (index1 < 0 || index1 > zb.size())
    {
        cout << "Zly index. Biore 0." << endl;
        index1 = 0;
    }

    cout << "Podaj indeks 2: ";
    int index2;
    cin >> index2;
    index2--;
    if (index2 < 0 || index2 > zb.size())
    {
        cout << "Zly index. Biore 0." << endl;
        index2 = 0;
    }

    if(index2-index1 >= zb.size()) {
        cout << "Zle podane indeksy. Wracam." << endl;
        return;
    }

    while (index2 - index1 >= 0)
    {
        cout << "Podaj liczbe:";
        int liczba;
        cin >> liczba;
        zb.at(index1++) = liczba;
    }
}
//********************************************************************************************************************************************
int main()
{
    while (true)
    {
        wypisz(zbior);
        cout << "Chcesz wprowadzic zmiany? 1 - Tak, 2 - Nie" << endl;
        int odp;
        cin >> odp;
        switch (odp)
        {
        case 1:
            zmiana(zbior);
            break;

        default:
            return 0;
        }
    }
}