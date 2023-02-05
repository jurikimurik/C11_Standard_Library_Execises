// Zadanie 5. Stworz vector, ktory wypelnisz 15-oma losowymi liczbami z zakresu od 1-5. Nastpenie za pomoca iteratora const sprawdz jak duzo razy powtarza sie losowa (lub wybrana przez Ciebie) liczba
#include <vector>
#include <iostream>
using namespace std;
//*****************************************************************************************************************************************************************************************
int main()
{
    vector<int> liczby;

    srand(time(nullptr));
    for (int i = 0; i < 15; i++)
    {
        liczby.push_back(rand() % 5 + 1);
    }

    cout << "Losowo wybrana liczba: ";
    int losowa_liczba = rand() % 5 + 1;
    cout << losowa_liczba << endl;

    vector<int>::const_iterator pos = liczby.begin();
    int ilosc_pow = 0;

    for (int i = 0; i < liczby.size(); i++) {
        if(*pos++ == losowa_liczba)
            ilosc_pow++;
    }

    cout << "Ilosc powtorzen: " << ilosc_pow << endl;
}