// Zadanie 3 - Analizator tekstu v.2. Uzytkownik wprowadza tekst. Twoim zadaniem jest przeanalizowac go i wypisac ilosc kazdej z poszczegolnych liter.
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
//****************************************************************************************************************************************************************
template<typename T>
T wprowadz(string napis)
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//****************************************************************************************************************************************************************
template <>
string wprowadz(string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);
    return zmienna;
}
//****************************************************************************************************************************************************************
map<char, int> analizuj(string text)
{
    auto pos = text.begin();
    map<char, int> dane;

    while(pos != text.end())
    {
        if(auto czy_pos = dane.find(*pos); czy_pos == dane.cend())
        {
            dane.insert(make_pair(*pos, 1));
        } else {
            czy_pos->second++;
        }

        pos++;
    }

    return dane;
}
//****************************************************************************************************************************************************************
void wypisz_wyniki(map<char, int> dane)
{
    
    for(const auto& elem : dane)
    {
        cout << "Litera \'" << elem.first << "\': " << elem.second << endl;
    }
}
//****************************************************************************************************************************************************************
int main()
{
        string text = wprowadz<string>("Wprowadz tekst: ");
        wypisz_wyniki(analizuj(text));   

}