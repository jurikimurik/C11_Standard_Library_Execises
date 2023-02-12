// Zadanie 3 - Pirackie kluczy i diabelskie skrzynki. Gracz posiada okreslona liczbe losowych kluczy do skrzyn. Problem polega na tym,
// ze wszystkie kluczy pasuja do wszystkich skrzynek, ale nagrody sa rozne. Zeby zrozumiec jaki klucz najlepiej pasuje do ktorejs skrzynki
// trzeba spytac sie u diabla, ale on da matematyczne rownanie do rozwiazania. Gracz wtedy poda odpowiedz, ale diabel nie powie czy odpowiedz
// jest dobra czy nie. Jedynie powie jaki skarb na niego czeka, jezeli wlozy ten okreslony klucz, ale moze to byc klamstwem, jezeli
// uzytkownik powiedzial zla liczbe.
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> rodzaje = {"Klucz Piracki", "Klucz Smokow", "Klucz Losu", "Klucz Diabelski", "Klucz Wikingow"};
vector<string> dopasowania = {"Skrzynia Jednookiego Jeffry", "Skrzynia Belzebuba", "Skrzynia Losu", "Skrzynia Boga", "Skrzynia Morza"};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class klucz
{
    public:
        klucz(string i = rodzaje.at(rand() % rodzaje.size())) : id(i){}

        string id;
        string dopasowanie;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using rodzaj_klucza = string;
using nagroda = int;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
map<rodzaj_klucza, nagroda> skrzynia_Jednookiego_Jeffry;
map<rodzaj_klucza, nagroda> skrzynia_Belzebuba;
map<rodzaj_klucza, nagroda> skrzynia_Losu;
map<rodzaj_klucza, nagroda> skrzynia_Boga;
map<rodzaj_klucza, nagroda> skrzynia_Morza;
//***********************************************************************************************************************************************
void wypelnienie_mapy(map<rodzaj_klucza, nagroda>& mapa, rodzaj_klucza ktory_najbardziej_wynagradzany)
{
    mapa.insert(make_pair(ktory_najbardziej_wynagradzany, 80 * (rand() % 10)));

    for (int i = 0; i < rodzaje.size(); ++i)
    {
        if(rodzaje.at(i) != ktory_najbardziej_wynagradzany)
        {
            mapa.insert(make_pair(rodzaje.at(i), rand() % 100));
        }
    }
       
}
//***********************************************************************************************************************************************
void inicjalizacja()
{
    srand(time(NULL));
    wypelnienie_mapy(skrzynia_Jednookiego_Jeffry, rodzaje.at(0));
    wypelnienie_mapy(skrzynia_Belzebuba, rodzaje.at(1));
    wypelnienie_mapy(skrzynia_Losu, rodzaje.at(2));
    wypelnienie_mapy(skrzynia_Boga, rodzaje.at(3));
    wypelnienie_mapy(skrzynia_Morza, rodzaje.at(4));
}
//***********************************************************************************************************************************************
int main()
{
        inicjalizacja();

        for(const auto& elem : skrzynia_Jednookiego_Jeffry)
        {
            cout << elem.first << " - " << elem.second << endl;
        }
}
