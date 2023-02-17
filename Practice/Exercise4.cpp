//Zadanie 4 - Lista dzialan. Niech uzytkownik wprowadzi liste zadan na dzis. Nastepnie bedzie mogl ja edytowac: dodawac, usuwac, zmieniac, zamieniac miejscami, zapisywac i 
//odczytywac.
#include <iostream>
#include <list>
#include <vector>
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
void dodaj_lub_usun_zadania(lista& zadania)
{
    int odpowiedz = wprowadzenie<int>("1 - dodawanie, 2 - usuwanie: ");
    lista nowe_zadania;
    if(odpowiedz == 1)
    {
        nowe_zadania = pobierz_dzialania();
        odpowiedz = wprowadzenie<int>("Gdzie chcesz ich dodac? Podaj numer:");

        auto pos = zadania.begin();
        advance(pos, --odpowiedz);

        zadania.splice(pos, nowe_zadania);
    } else if(odpowiedz == 2) {
        vector<lista::iterator> pozycje;

        cout << "Podaj pozycje rozdzielajac ich spacjami i na koniec wprowadz 'q': ";
        while(true)
        {
            int pozycja = wprowadzenie<int>();
            if(!cin)
            {
                cin.clear();
                cin.ignore();
                break;
            }

            lista::iterator pos = zadania.begin();
            advance(pos, --pozycja);
            pozycje.push_back(pos);
        }

        for(auto& elem : pozycje)
        {
            zadania.erase(elem);
        }
        
    } else {
        cout << "Niezrozumiale zadanie" << endl;
    }
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
        case 1:
            dodaj_lub_usun_zadania(zadania);
            break;
        case 2:
            //zmien_zadanie(zadania);
            break;
        case 3:
            //zamien_miejscami(zadania);
            break;
        case 4:
            //zapis_lub_odczyt(zadania);
            break;
        case 5:
            exit(0);
            break;
    
        default:
            break;
        }
    }
}