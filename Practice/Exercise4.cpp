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
bool sprawdzenie_pozycji(int& pozycja, lista& zadania)
{
    if(pozycja < 0 || pozycja > zadania.size())
    {
        return false;
    } else {
        return true;
    }
}
//******************************************************************************************************************************************************************
lista wczytaj_liste()
{
    string nazwa = wprowadzenie<string>("Podaj nazwe pliku bez rozszerzenia .tasks: ");
    nazwa += ".tasks";

    ifstream strm(nazwa);
    if(!strm)
    {
        cout << "Nie udalo sie wczytac pliku!" << endl;
    }

    lista zadania;
    while(true)
    {
        string text;
        getline(strm, text);
        if(!strm)
            break;
        else
            zadania.push_back(text);
    }

    strm.close();

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
    
    while(true)
    {
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

        while(true)
        {
            odpowiedz = wprowadzenie<int>("Gdzie chcesz ich dodac? Podaj numer:");
            if(odpowiedz < 0 || odpowiedz >= zadania.size())
            {
                cout << "Zle podany numer." << endl;
            } else {
                break;
            }
        }

        auto pos = zadania.begin();
        advance(pos, --odpowiedz);

        zadania.splice(pos, nowe_zadania);
    } else if(odpowiedz == 2) {
        vector<lista::iterator> pozycje;

        cout << "Podaj pozycje rozdzielajac ich spacjami i na koniec wprowadz 'q': ";
        while(true)
        {
            int pozycja = wprowadzenie<int>();
            if(!sprawdzenie_pozycji(pozycja, zadania) && cin)
            {
                cout << "Zla pozycja: " << pozycja << endl;
                cout << "Zacznij od nowa!" << endl;
                pozycje.clear();
            }
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
void zmien_zadanie(lista& zadania)
{
    int odpowiedz = 0;
    while(true)
    {
        odpowiedz = wprowadzenie<int>("Podaj numer zadania, ktorego opis chcesz zmienic: ");
        if(sprawdzenie_pozycji(odpowiedz, zadania))
        {
            break;
        } else {
            cout << "Zle podana pozycja" << endl;
        }
    }
   
    jednostka na_co_zmienic = wprowadzenie<jednostka>("Podaj zadanie: ");

    auto pos = zadania.begin();
    advance(pos, --odpowiedz);
    auto pos_k = pos;
    pos_k++;

    cout << *pos << " - " << na_co_zmienic << endl;
    replace(pos, pos_k, *pos, na_co_zmienic);
    
}
//******************************************************************************************************************************************************************
void zamien_miejscami(lista& zadania)
{
    int ktory_p; 
    int ktory_d;
    while(true)
    {
        ktory_p = wprowadzenie<int>("Wprowadz pozycje numer 1: ");
        if(sprawdzenie_pozycji(ktory_p, zadania))
        {
            break;
        } else {
            cout << "Zla pozycja." << endl;
        }
    }
    while (true)
    {
        ktory_d = wprowadzenie<int>("Wprowadz pozycje numer 2: ");
        if(sprawdzenie_pozycji(ktory_d, zadania))
        {
            break;
        } else {
            cout << "Zla pozycja." << endl;
        }
    }
    
    

    auto pos_p = zadania.begin();
    auto pos_d = zadania.begin();

    advance(pos_p, --ktory_p);
    advance(pos_d, --ktory_d);

    iter_swap(pos_p, pos_d);
}
//******************************************************************************************************************************************************************
void zapis(lista& zadania)
{
    string nazwa = wprowadzenie<string>("Podaj nazwe pliku bez roszerzenia .tasks: ");

    nazwa += ".tasks";

    ofstream strm(nazwa);
    if(!strm)
    {
        cout << "Nie udalo sie otworzyc plik do zapisu!" << endl;
        return;
    }

    for(const auto& elem: zadania)
    {
        strm << elem << endl;
    }

    strm.close();
}
//******************************************************************************************************************************************************************
void zapis_lub_odczyt(lista& zadania)
{
    int odpowiedz = wprowadzenie<int>("1 - zapis, 2 - odczyt: ");
    lista dodatkowo;
    switch (odpowiedz)
    {
    case 1:
        zapis(zadania);
        break;
    case 2:
        dodatkowo = wczytaj_liste();
        
        if(!dodatkowo.empty())
            zadania = dodatkowo;
        else
            cout << "Pusty. Nie wczytuje. " << endl;
        break;
    default:
        cout << "Zadanie niezdefiniowane!" << endl;
        break;
    }
}
//******************************************************************************************************************************************************************
int main()
{
    
    lista zadania;

    while(zadania.empty())
    {
        zadania = stworz_poczatkowa_liste();
        if(zadania.empty())
            cout << "Lista nie moze byc pusta!" << endl;
    }

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
            zmien_zadanie(zadania);
            break;
        case 3:
            zamien_miejscami(zadania);
            break;
        case 4:
            zapis_lub_odczyt(zadania);
            break;
        case 5:
            exit(0);
            break;
    
        default:
            break;
        }
    }
}