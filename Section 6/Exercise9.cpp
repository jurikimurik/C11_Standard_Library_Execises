// Zadanie 9 - Super-Dzialacz na kontenerach. Niech uzytkownik wprowadzi pewne dane do konteneru vector. Nastepnie zaprogramuj dzialanie programu tak, zeby dało się z tym kontenerem robic nastepujace
// rzeczy: sortowanie, sortowanie wstecz, wstawianie, odwrocenie kolejnosci, sprawdzenie czy element istnieje w kontenerze.
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//****************************************************************************************************************************************************
enum class sortowanie
{
    normalne = 0,
    wstecz = 1
};

//****************************************************************************************************************************************************
void wypisanie(vector<int>& liczby)
{
    cout << "Ciag: ";
    for (const auto &elem : liczby)
    {
        cout << elem << ' ';
    }
    cout << endl
         << endl;
}

//****************************************************************************************************************************************************
void wprowadzenie(vector<int>& liczby) {
    while (true)
    {
        cout << "Wprowadz liczbe [" << liczby.size() + 1 << "]:";
        int liczba;
        cin >> liczba;
        if (!cin)
            break;
        liczby.push_back(liczba);
    }
    cin.clear();
    cin.ignore();
}

//****************************************************************************************************************************************************
void sortowanie(vector<int>& liczby, enum sortowanie opcja) {
    sort(liczby.begin(), liczby.end());
    if(opcja == sortowanie::wstecz)
        sort(liczby.begin(), liczby.end(), [](int a, int b)
             { return a > b ? a : b; });
}

//****************************************************************************************************************************************************
void wstawianie(vector<int>& liczby) {
    cout << "Podaj pozycje: ";
    int pozycja;
    cin >> pozycja;
    if(pozycja < 0)
        pozycja = 1;
    if(pozycja > liczby.size())
        pozycja = liczby.size();
    pozycja--;

    vector<int> inne_liczby;

    wprowadzenie(inne_liczby);

    copy(inne_liczby.cbegin(), inne_liczby.cend(), inserter(liczby, liczby.begin() + pozycja));
}

//****************************************************************************************************************************************************
void odwrocenie(vector<int>& liczby) {
    reverse(liczby.begin(), liczby.end());
}

//****************************************************************************************************************************************************
void sprawdzenie(vector<int>& liczby) {
    cout << "Podaj liczbe do sprawdzenia: ";
    int liczba;
    cin >> liczba;

    auto iter = find(liczby.begin(), liczby.end(), liczba);
    if(iter == liczby.end()) {
        cout << "-------Nie istnieje w kontenerze!--------" << endl << endl;
    } else {
        cout << "------- Znalezione! --------" << endl << endl;
    }
}

//****************************************************************************************************************************************************
int main()
{
    vector<int> liczby;

    wprowadzenie(liczby);

    bool dzialania = true;
    while(dzialania) {
        wypisanie(liczby);
        cout << "Wybierz dzialanie: 1 - sortowanie, 2 - sortowanie wstecz, 3 - odwrocenie, 4 - sprawdzenie, 5 - wstawianie, 6 - wyjscie\n - ";
        int opcja;
        cin >> opcja;
        
        switch (opcja)
        {
        case 1:
            sortowanie(liczby, sortowanie::normalne);
            break;
        case 2:
            sortowanie(liczby, sortowanie::wstecz);
            break;
        case 3:
            odwrocenie(liczby);
            break;
        case 4:
            sprawdzenie(liczby);
            break;
        case 5:
            wstawianie(liczby);
            break;
        case 6:
            dzialania = false;
            break;

        default:
            cin.clear();
            cin.ignore();
            break;
        }
    }
}