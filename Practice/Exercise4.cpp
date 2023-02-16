//Zadanie 4 - Lista dzialan. Niech uzytkownik wprowadzi liste zadan na dzis. Nastepnie bedzie mogl ja edytowac: dodawac, usuwac, zmieniac, zamieniac miejscami, zapisywac i 
//odczytywac.
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using jednostka = string;
using lista = list<jednostka>;
//******************************************************************************************************************************************************************
template <typename T>
T wprowadzenie(string napis = "")
{
    cout << napis;
    T zmienna;
    cin >> zmienna;
    return zmienna;
}
//******************************************************************************************************************************************************************
template <>
string wprowadzenie(string napis)
{
    cout << napis;
    string zmienna;
    getline((cin >> ws), zmienna);
    return zmienna;
}
//******************************************************************************************************************************************************************
lista wczytaj_liste()
{
    string nazwa = wprowadzenie<string>("Podaj nazwe pliku bez rozszerzenia .tasks: ");

    ifstream strm(nazwa);
    if(!strm)
    {
        cout << "Nie udalo sie wczytac pliku!" << endl;
    }

    lista zadania;
    while(true)
    {
        string text;
        strm >> text;
        if(!strm)
            break;
        else
            zadania.push_back(text);
    }

    return zadania;
}
//******************************************************************************************************************************************************************
lista pobierz_dzialania(string napis = "")
{
    cout << napis;
    
    lista zadania;
    string zadanie;

    while(true)
    {
        zadanie = wprowadzenie<string>("Wpisz dzialania po kolei uzywajac ENTER a skoncz wprowadzenie litera \'q\': ");
        if(zadanie == "q")
            break;
        zadania.push_back(zadanie);
    }
    

    return zadania;
}
//******************************************************************************************************************************************************************
lista stworz_poczatkowa_liste()
{
    cout << "1 - nowa lista, 2 - wczytaj liste. " << endl;
    int odpowiedz = wprowadzenie<int>("Wybierz dzialanie: ");
    switch (odpowiedz)
    {
    case 1:
        return pobierz_dzialania();
        break;
    case 2:
        return wczytaj_liste();
        break;
    
    default:
        break;
    }
}
//******************************************************************************************************************************************************************
void wypisz_liste(lista zadania)
{
    auto pos = zadania.begin();
    for(int i = 1; pos != zadania.end(); ++i, pos++)
    {
        cout << i << " - " << *pos << endl;
    }
    cout << endl << endl;
}
//******************************************************************************************************************************************************************
void wypisz_dzialania()
{
    cout << "1 - dodaj/usun zadania, 2 - zmien zadanie, 3 - zamiana miejsc, 4 - zapis/odczyt, 5 - wyjscie" << endl;
}

//******************************************************************************************************************************************************************
int main()
{
    lista zadania = stworz_poczatkowa_liste();

    while(true)
    {
        wypisz_liste(zadania);
        wypisz_dzialania();
        int odpowiedz = wprowadzenie<int>("Wybierz dzialanie: ");
        switch (odpowiedz)
        {
        case 5:
            exit(0);
            break;
    
        default:
            break;
        }
    }
}