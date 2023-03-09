// Zadanie 24 - Stogownica. Niech użytkownik wprowadzi liczby. Następnie stwórz z nich stóg. Pozwól użytkownikowi dodawać tam elementy 
// oraz ich usuwać. Na koniec niech użytkownik dostanie posortowana tablice.
#include "narzedzia.h"
#include <vector>
using namespace std;

vector<int> wprowadz_liczby()
{
    vector<int> liczby;

    cout << "Wprowadz liczby rozdzielajac ich spacjami a nastepnie wpisz znak q:";
    while (cin)
    {
        int liczba = wprowadzenie<int>();
        liczby.push_back(liczba);
    }
    cin.clear();
    cin.ignore();
    liczby.pop_back();

    return liczby;
}

void dodaj_liczbe_na_stog(vector<int>& liczby)
{
    int liczba = wprowadzenie<int>("Wprowadz liczbe: ");
    liczby.push_back(liczba);
    push_heap(liczby.begin(), liczby.end());
}

void usun_liczbe_ze_stogu(vector<int> &liczby)
{
    int liczba = wprowadzenie<int>("Wprowadz liczbe: ");
    liczby.erase(find(liczby.begin(), liczby.end(), liczba));
    pop_heap(liczby.begin(), liczby.end());
}

int main()
{
    vector<int> liczby = wprowadz_liczby();

    make_heap(liczby.begin(), liczby.end());

    while(true)
    {
        drukuj(liczby, "", "\n");

        int odpowiedz = wprowadzenie<int>("1 - dodaj liczbe, 2 - usun liczbe, 3 - skoncz ze stogiem: ");

        switch (odpowiedz)
        {
        case 1:
            dodaj_liczbe_na_stog(liczby);
            break;
        
        case 2:
            usun_liczbe_ze_stogu(liczby);
            break;
        
        case 3:
            sort_heap(liczby.begin(), liczby.end());
            drukuj(liczby);
            return 0;

        default:
            break;
        }

        cout << endl;
    }
}