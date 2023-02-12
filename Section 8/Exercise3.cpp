// Zadanie 3 - Pirackie kluczy i diabelskie skrzynki. Gracz posiada okreslona liczbe losowych kluczy do skrzyn. Problem polega na tym,
// ze wszystkie kluczy pasuja do wszystkich skrzynek, ale nagrody sa rozne. Zeby zrozumiec jaki klucz najlepiej pasuje do ktorejs skrzynki
// trzeba spytac sie u diabla, ale on da matematyczne rownanie do rozwiazania. Gracz wtedy poda odpowiedz, ale diabel nie powie czy odpowiedz
// jest dobra czy nie. Jedynie powie jaki skarb na niego czeka, jezeli wlozy ten okreslony klucz, ale moze to byc klamstwem, jezeli
// uzytkownik powiedzial zla liczbe.
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> rodzaje = {"Klucz Piracki", "Klucz Smokow", "Klucz Losu", "Klucz Diabelski", "Klucz Wikingow"};
vector<string> dopasowania = {"Skrzynia Jednookiego Jeffry", "Skrzynia Belzebuba", "Skrzynia Losu", "Skrzynia Boga", "Skrzynia Morza"};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using rodzaj_klucza = string;
using nagroda = int;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class klucz
{
    public:
    klucz(string i = rodzaje.at(rand() % rodzaje.size())) : id(i) {}
    string id;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class skrzynia
{
    public:
    skrzynia(string str) : nazwa("Skrzynia " + str)
    {
        najlepszy_klucz = klucz();
    }

    string nazwa;
    klucz najlepszy_klucz;

    bool operator<(const skrzynia &another) const
    {
        return nazwa < another.nazwa;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<skrzynia> wszystkie_skrzynie = {skrzynia("Jednookiego Jeffry"), skrzynia("Belzebuba"), skrzynia("Losu"), skrzynia("Boga"), skrzynia("Morza")};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
map<skrzynia, rodzaj_klucza> najlepsze_dopasowania;
//***********************************************************************************************************************************************
void inicjalizacja()
{
    srand(time(NULL));

    shuffle(rodzaje.begin(), rodzaje.end(), mt19937());
    shuffle(dopasowania.begin(), dopasowania.end(), mt19937());

    for(const auto& elem : wszystkie_skrzynie)
    {
        najlepsze_dopasowania.insert(make_pair(elem, elem.najlepszy_klucz.id));
    }
}
//***********************************************************************************************************************************************
int pobierz_odpowiedz(string napis = "")
{
    cout << napis;
    int liczba;
    cin >> liczba;
    return liczba;
}
//***********************************************************************************************************************************************
pair<string, int> zagadka(int trudnosc = 1)
{
    return make_pair("Ile bedzie 2+2?", 4);
}
//***********************************************************************************************************************************************
void wskazowka_od_diabla(skrzynia co_za_skrzynia, int trudnosc)
{
    cout << "Chcesz wskazowki?! Ale najpierw podaj odpowiedz: ";

    pair<string, int> zag = zagadka(trudnosc);

    cout << zag.first << endl;
    int odpowiedz = pobierz_odpowiedz("Podaj odpowiedz: ");

    cout << "Dla skrzyni " << co_za_skrzynia.nazwa << " najlepiej by pasowal: ";
    if (odpowiedz == zag.second)
    {
        cout << najlepsze_dopasowania.at(co_za_skrzynia) << endl;
    }
    else
    {
        cout << rodzaje.at(rand() % rodzaje.size()) << endl;
    }
}
//***********************************************************************************************************************************************
int main()
{
    inicjalizacja();
    for (const auto &elem : najlepsze_dopasowania)
    {
        cout << elem.first.nazwa << ", " << elem.second << endl;
    }
}
