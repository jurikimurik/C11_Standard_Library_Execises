// Zadanie 2 - Szybkie losowe liczby. Za pomoca funkcji generate_n, zgeneruj okreslona ilosc losowych liczb z dolnym i gornym zakresem(przekaz generate_n obiekt funkcyjny z okreslonym stanem wewnetrznym)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class LosowaLiczba
{
    private:
        int dolny_zakres;
        int gorny_zakres;

    public:
        LosowaLiczba(int d, int g) : dolny_zakres(d), gorny_zakres(g) {}

    int operator() ()
    {
        return rand() % (gorny_zakres - dolny_zakres) + dolny_zakres;
    }
};
//**********************************************************************************************************************************************************************************************
int main()
{
    vector<int> liczby_losowe;

    cout << "Podaj ilosc liczb losowych: ";
    int ilosc;
    cin >> ilosc;

    cout << "Podaj dolny zakres: ";
    int dol;
    cin >> dol;

    cout << "Podaj gorny zakres: ";
    int gora;
    cin >> gora;
    gora++;

    srand(time(NULL));
    LosowaLiczba generator(dol, gora);

    generate_n(back_inserter(liczby_losowe), ilosc, generator);

    for(const auto& elem : liczby_losowe)
    {
        cout << elem << ", ";
    }
    cout << endl;
}