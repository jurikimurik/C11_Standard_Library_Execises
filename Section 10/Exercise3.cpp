// Zadanie 3 - Kalkulator zbiorowy. Niech uzytkownik wprowadzi n liczb. Nastpenie pozwol uzytkownikowi do kazdej z tych liczb: dodac, odjac, pomnozyc przez, podzielic przez. Uzyj w tym celu bind().
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
//****************************************************************************************************************************************************************************
int daj_liczbe()
{
    cout << "Wprowadz liczbe: ";
    int liczba;
    cin >> liczba;
    return liczba;
}
//****************************************************************************************************************************************************************************
void dodaj(vector<int>& liczby)
{
    int liczba = daj_liczbe();

    transform(liczby.begin(), liczby.end(), liczby.begin(), bind(plus<int>(), placeholders::_1, liczba));
}
//****************************************************************************************************************************************************************************
void odejmij(vector<int> &liczby)
{
    int liczba = daj_liczbe();

    transform(liczby.begin(), liczby.end(), liczby.begin(), bind(minus<int>(), placeholders::_1, liczba));
}
//****************************************************************************************************************************************************************************
void pomnoz(vector<int> &liczby)
{
    int liczba = daj_liczbe();

    transform(liczby.begin(), liczby.end(), liczby.begin(), bind(multiplies<int>(), placeholders::_1, liczba));
}
//****************************************************************************************************************************************************************************
void podziel(vector<int> &liczby)
{
    int liczba = daj_liczbe();

    transform(liczby.begin(), liczby.end(), liczby.begin(), bind(divides<int>(), placeholders::_1, liczba));
}
//****************************************************************************************************************************************************************************
int main()
{
    vector<int> liczby;

    cout << "Wprowadz ciag liczby rozdielajac ich spacja a nastepnie wprowadz 'q': ";
    while (cin)
    {
        int liczba;
        cin >> liczba;
        liczby.push_back(liczba);
    }
    liczby.pop_back();
    cin.clear();
    cin.ignore();

    while(true)
    {
        for(const auto& elem : liczby)
        {
            cout << elem << ", ";
        }
        cout << endl;

        cout << "Wybierz dzialanie na WSZYSTKICH liczbach: 1 - dodawanie, 2 - odejmowanie, 3 - mnozenie przez, 4 - dzielenie przez, 5 - wyjscie: ";
        int odpowiedz;
        cin >> odpowiedz;

        switch (odpowiedz)
        {
        case 1:
            dodaj(liczby);
            break;
        case 2:
            odejmij(liczby);
            break;
        case 3:
            pomnoz(liczby);
            break;
        case 4:
            podziel(liczby);
            break;
        case 5:
            exit(0);
            break;

        default:
            break;
        }
    }
    
}