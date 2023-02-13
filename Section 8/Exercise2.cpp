// Zadanie 2 - Drzewo binarne z polecenia. Niech uzytkownik wprowadzi najpierw tryb: postfix / prefix. Nastepnie niech wprowadzi okreslone
// symbole az do znaku 'q', wtedy jest koniec wprowadzania. Niech program zgeneruje wizualne drzewo binarne na podstawie wprowadzonych
// przez uzytkownika danych.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<char> operacje = {'+', '-', '*', '/'};
//****************************************************************************************************************
bool czyOperacja(char znak)
{
    if(find(operacje.begin(), operacje.end(), znak) != operacje.end())
    {
        return true;
    } else {
        return false;
    }
}
//****************************************************************************************************************
void wypisz_tryby()
{
    cout << "1 - postfix, 2 - prefix, 3 - exit" << endl;
}
//****************************************************************************************************************
int pobierz_odpowiedz(string napis)
{
    cout << napis;
    int odpowiedz;
    cin >> odpowiedz;
    return odpowiedz;
}
//****************************************************************************************************************
void wybierz_tryb()
{
    wypisz_tryby();

    int odpowiedz = pobierz_odpowiedz("Wybierz tryb: ");

    switch (odpowiedz)
    {
    case 1:
        // postfix
        break;
    case 2:
        // prefix
        break;
    case 3:
        exit(0);
        break;

    default:
        break;
    }
}

//****************************************************************************************************************
vector<char> wprowadz_dane()
{
    vector<char> dane;

    cout << "Wprowadzaj zmienne/operacje rodzialajac ich spacja (np. + 1 2) a zakoncz wprowadzajac 'q': ";
    while(true)
    {
        char znak;
        cin >> znak;

        if(znak == 'q')
            break;
        else
            dane.push_back(znak);
    }

    return dane;
}
//****************************************************************************************************************
void wypisz(vector<char> zbior)
{
    for(const auto& elem : zbior)
    {
        cout << elem;
    }
    cout << endl;
}
//****************************************************************************************************************
int main()
{
    while(true)
    {
        wybierz_tryb();

        vector<char> dane = wprowadz_dane();

        wypisz(dane);
        // wypisz(analizuj(dane));
    }
}