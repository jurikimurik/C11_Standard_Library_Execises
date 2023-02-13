// Zadanie 2 - Drzewo binarne z polecenia. Niech uzytkownik wprowadzi najpierw tryb: postfix / prefix. Nastepnie niech wprowadzi okreslone
// symbole az do znaku 'q', wtedy jest koniec wprowadzania. Niech program zgeneruje wizualne drzewo binarne na podstawie wprowadzonych
// przez uzytkownika danych.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class tryb_pracy
{
    postfix = 0,
    prefix
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
tryb_pracy tryb;
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
        tryb = tryb_pracy::postfix;
        break;
    case 2:
        tryb = tryb_pracy::prefix;
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
vector<char> analizuj(vector<char> dane)
{
    vector<char> kopia(dane);

    vector<char> wek1;
    vector<char> wek2;
    vector<char> wek3;
    vector<char> wek4;

    int poziom = 0;

    auto pos = kopia.begin();
    if(czyOperacja(*pos))
        poziom++; // 1
    wek1.push_back(*pos++);
    // operacja - kolejny poziom zagniezdzenia
    if(czyOperacja(*pos))
        poziom++; // 2
    wek2.push_back(*pos++);
    // operacja - kolejny poziom zagniezdzenia
    wek3.push_back(*pos++);
    if(czyOperacja(*pos))
        poziom++; // 4
    wek3.push_back(*pos++);
    // operacja - kolejny poziom zagniezdzenia
    wek4.push_back(*pos++);
    wek4.push_back(*pos++);
    poziom--; // 3
    // brak operacji - wracamy
    // wek3
    poziom--; // 2
    // koniec z tamtymi rowniez
    // wek2
    wek2.push_back(*pos++);
    poziom++; // 3
    // operacja - kolejny poziom zagniezdzenia
    wek3.push_back(*pos++);
    wek3.push_back(*pos++);
    poziom--; // 2
    // brak operacji - wracamy
    // wek2
    poziom--; // 1
    // brak operacji - wracamy
    // wek1
    // KONIEC BO WEK1

    for(const auto& elem : wek1)
    {
        cout << elem;
    }
    cout << endl;
    for (const auto &elem : wek2)
    {
        cout << elem;
    }
    cout << endl;
    for (const auto &elem : wek3)
    {
        cout << elem;
    }
    cout << endl;
    for (const auto &elem : wek4)
    {
        cout << elem;
    }
    cout << endl;

    return kopia;
}
//****************************************************************************************************************
int main()
{

        //wybierz_tryb();

        vector<char> dane = {'/', '*', '2', '+', 'a', '3', '+', 'b', '4'}; //= wprowadz_dane();

        wypisz(analizuj(dane));
}