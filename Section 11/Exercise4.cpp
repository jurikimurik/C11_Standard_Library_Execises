// Zadanie 4 - Poszukiwac znakow. Masz podany ciag. Pozwol uzytkownikowi wyszukac podciag w tym ciagu i wypisz rezultat. Musi byc
// niewrazliwe na wielkosc liter.
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
//******************************************************************************************************************
void to_lower_string(string& tekst)
{
    auto pos = tekst.begin();
    while(pos != tekst.end())
    {
        *pos = tolower(*pos);
        pos++;
    }
}
//******************************************************************************************************************
string wez_tekst(string napis = "", bool zmniejsz = true)
{
    cout << napis;
    string tekst;
    getline((cin >> ws), tekst);

    if(zmniejsz)
        to_lower_string(tekst);

    return tekst;
}
//******************************************************************************************************************
int main()
{
    string tekst = wez_tekst("Wpisz caly tekst: ");

    string pod_tekst = wez_tekst("Wpisz podtekst, ktory chcesz znalezc: ");

    if (search(tekst.begin(), tekst.end(), pod_tekst.begin(), pod_tekst.end()) != tekst.end())
    {
        cout << "Ciag zostal znaleziony!" << endl;
    } else {
        cout << "Ciag NIE zostal znaleziony!" << endl;
    }
}