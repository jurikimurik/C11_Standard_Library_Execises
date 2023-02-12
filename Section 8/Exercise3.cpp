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
using rodzaj_klucza = string;
using nagroda = int;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> rodzaje = {"Klucz Piracki", "Klucz Smokow", "Klucz Losu", "Klucz Diabelski", "Klucz Wikingow"};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class klucz
{
public:
    klucz(string i = rodzaje.at(rand() % rodzaje.size())) : id(i) {}
    string id;

    bool operator==(const klucz& drugi)
    {
        if(id == drugi.id)
            return true;
        else
            return false;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class skrzynia
{
public:
    skrzynia(string str, int zw_w = 10, int w = 100) : nazwa("Skrzynia " + str)
    {
        najlepszy_klucz = klucz();
    }

    string nazwa;
    klucz najlepszy_klucz;

    int zwykla_wygrana;
    int wygrana;

    bool operator<(const skrzynia &another) const
    {
        return nazwa < another.nazwa;
    }

    bool operator==(const skrzynia& druga)
    {
        return nazwa == druga.nazwa && najlepszy_klucz == druga.najlepszy_klucz && zwykla_wygrana == druga.zwykla_wygrana && wygrana == druga.wygrana;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<skrzynia> wszystkie_skrzynie = {skrzynia("Jednookiego Jeffry"), skrzynia("Belzebuba"), skrzynia("Losu"), skrzynia("Boga"), skrzynia("Morza")};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
map<skrzynia, rodzaj_klucza> najlepsze_dopasowania;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<klucz> klucze_uzytkownika;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<skrzynia> skrzynki;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int zloto = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
size_t poziom_trudnosci = 1;
//***********************************************************************************************************************************************
void inicjalizacja(int ilosc_kluczy = 5)
{
    srand(time(NULL));

    shuffle(rodzaje.begin(), rodzaje.end(), mt19937());

    for(const auto& elem : wszystkie_skrzynie)
    {
        najlepsze_dopasowania.insert(make_pair(elem, elem.najlepszy_klucz.id));
    }

    for (int i = 0; i < ilosc_kluczy; ++i)
    {
        klucze_uzytkownika.push_back(klucz());

        skrzynia chest = wszystkie_skrzynie.at(rand() % wszystkie_skrzynie.size());
        chest.wygrana = 50 * (rand() % 20);
        chest.zwykla_wygrana = rand() % 100;

        skrzynki.push_back(chest);
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
    int odpowiedz = rand() % 20;
    string pytanie = to_string(odpowiedz);

    for (int i = 0; i < trudnosc; ++i)
    {
        int liczba = rand() % 20;
        char operacja;
        switch (rand() % 4)
        {
        case 0:
            operacja = '+';
            odpowiedz += liczba;
            break;
        case 1:
            operacja = '-';
            odpowiedz -= liczba;
            break;
        case 2:
            operacja = '*';
            pytanie = "(" + pytanie + ")";
            odpowiedz *= liczba;
            break;
        case 3:
            operacja = '/';
            pytanie = "(" + pytanie + ")";
            odpowiedz /= liczba;
            break;
        default:
            break;
        }

        pytanie += operacja + to_string(liczba);
    }

    pytanie = "Ile bedzie " + pytanie + "?";
    return make_pair(pytanie, odpowiedz);
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
        poziom_trudnosci++;
    }
    else
    {
        cout << rodzaje.at(rand() % rodzaje.size()) << endl;
        poziom_trudnosci += rand() % 2;
    }
}
//***********************************************************************************************************************************************
void wypisz_skrzynie(vector<skrzynia>& chests = skrzynki, bool czy_z_id = false)
{
    int index = 1;

    cout << "Posiadane skrzynki: ";
    for (auto &elem : chests)
    {
        if(czy_z_id == true)
        {
            cout << index++ << " - ";
        }
        cout << elem.nazwa << ", ";
    }
    cout << endl;
}
//***********************************************************************************************************************************************
void wypisz_klucze(vector<klucz> &keys = klucze_uzytkownika, bool czy_z_id = false)
{
    int index = 1;

    cout  << "Posiadane klucze: ";
    for (const auto &elem : keys)
    {
        if (czy_z_id == true)
        {
            cout << index++ << " - ";
        }
        cout << elem.id << ", ";
    }
    cout << endl;
}

//***********************************************************************************************************************************************
void wypisz_dane_uzytkownika()
{
    cout << endl << endl << "Ilosc zlota: ";
    cout << zloto << " zlotowek. " << endl;

    wypisz_skrzynie();

    wypisz_klucze();
}
//***********************************************************************************************************************************************
klucz wybierz_klucz(vector<klucz> &klucze)
{
    wypisz_klucze(klucze, true);
    int jaki_klucz = pobierz_odpowiedz("Wybierz klucz: ");
    return klucze.at(jaki_klucz - 1);
}
//***********************************************************************************************************************************************
skrzynia wybierz_skrzynie(vector<skrzynia>& skrzynie)
{
    wypisz_skrzynie(skrzynie, true);
    int jaka_skrzynia = pobierz_odpowiedz("Wybierz skrzynie: ");
    return skrzynie.at(jaka_skrzynia - 1);
}
//***********************************************************************************************************************************************
void otworz_skrzynie(vector<skrzynia>& skrzynie, vector<klucz>& keys)
{
    cout << "\n\n";
    skrzynia sama_skrzynia = wybierz_skrzynie(skrzynie);
    klucz sam_klucz = wybierz_klucz(keys);
    

    int wygrana = 0;
    if (sam_klucz == sama_skrzynia.najlepszy_klucz)
    {
        wygrana += sama_skrzynia.wygrana;
    }
    else
    {
        wygrana += sama_skrzynia.zwykla_wygrana;
        poziom_trudnosci--;
    }

    cout << "Znalazles " << wygrana << " sztuk zlota!" << endl;
    zloto += wygrana;
    
    keys.erase(find(keys.begin(), keys.end(), sam_klucz));
    skrzynie.erase(find(skrzynie.begin(), skrzynie.end(), sama_skrzynia));
}
//***********************************************************************************************************************************************
void wypisz_dzialania()
{
    cout << "1 - otworzyc skrzynie kluczem, 2 - poprosic o wskazowke, 3 - skonczyc" << endl;
}
//***********************************************************************************************************************************************
void koniec(bool czy_dobrowolnie = false)
{
    klucze_uzytkownika.clear();
    skrzynki.clear();

    if (!czy_dobrowolnie)
        cout << "Skonczyly ci sie klucze!" << endl;
    else
        cout << "Skonczyles rozrywke!" << endl;

    cout << "Udalo ci sie zdobyc: " << zloto << " zlotych monet!" << endl;
    exit(0);
}

//***********************************************************************************************************************************************
void dzialanie_uzytkownika()
{
    int odpowiedz = pobierz_odpowiedz("Wybierz dzialanie: ");
    switch (odpowiedz)
    {
    case 1:
        otworz_skrzynie(skrzynki, klucze_uzytkownika);
        break;
    case 2:
        wskazowka_od_diabla(wybierz_skrzynie(skrzynki), poziom_trudnosci);
        break;
    case 3:
        koniec(true);
        break;

    default:
        break;
    }
}

//***********************************************************************************************************************************************
int main()
{
    inicjalizacja();

    while(!klucze_uzytkownika.empty())
    {
        wypisz_dane_uzytkownika();
        wypisz_dzialania();

        dzialanie_uzytkownika();
    }

    koniec();
}
