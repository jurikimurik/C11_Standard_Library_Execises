// Zadanie 1 - Poszukiwacz. Masz n liczb losowych. Pozwol uzytkownikowi znalezc interesujace jego liczby i wypisac ich na ekranie. 
// Poszukiwanie liczb ma sie odbyc wedlug okreslonych regul, takich jak: 1. modulo, 2. zakres.
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//************************************************************************************************************************
vector<int> liczby;
//************************************************************************************************************************
int pobierz_odpowiedz(string napis)
{
    cout << napis;
    int odp;
    cin >> odp;
    return odp;
}
//************************************************************************************************************************
vector<int> daj_losowy_zestaw()
{
    vector<int> losowe_liczby;

    int ilosc = pobierz_odpowiedz("Podaj ilosc liczb: ");
    int dolny = pobierz_odpowiedz("Podaj dolny zakres: ");
    int gorny = pobierz_odpowiedz("Podaj gorny zakres: ");

    srand(time(NULL));
    for (int i = 0; i < ilosc; ++i)
    {
        losowe_liczby.push_back(rand() % (gorny - dolny) + dolny);
    }

    return losowe_liczby;
}
//************************************************************************************************************************
void wypisz(const vector<int>& liczby, string napis = "")
{
    cout << napis;

    if(!liczby.empty())
    {
        for (const auto &elem : liczby)
        {
            cout << elem << ", ";
        }
        cout << endl
             << endl;
    } else {
        cout << "BRAK LICZB" << endl;
    }
}
//************************************************************************************************************************
void wypisz_dzialania()
{
    cout << "Znajdz interesujace liczby wedlug: 1 - podzielnosci, 2 - zakresu. Wpisz 3 zeby wyjsc. " << endl;
}
//************************************************************************************************************************
vector<int> modulo(const vector<int>& liczby)
{
    vector<int> kopia = liczby;

    int podzielnosc = pobierz_odpowiedz("Podaj przez co musza byc podzielne liczby: ");

    kopia.erase(remove_if(kopia.begin(), kopia.end(), [&podzielnosc](int i)
                          { return i % podzielnosc; }),
                kopia.end());

    return kopia;
}
//************************************************************************************************************************
vector<int> zakres(const vector<int> &liczby)
{
    vector<int> kopia = liczby;

    int dolny = pobierz_odpowiedz("Podaj dolny zakres liczb: ");
    int gorny = pobierz_odpowiedz("Podaj gorny zakres liczb: ");

    kopia.erase(remove_if(kopia.begin(), kopia.end(), [&](int i)
                          { return i < dolny || i > gorny; }),
                kopia.end());

    return kopia;
}
//************************************************************************************************************************
int main()
{
    liczby = daj_losowy_zestaw();

    while(true)
    {
        wypisz(liczby);
        wypisz_dzialania();
        int odpowiedz = pobierz_odpowiedz("Wpisz dzialanie: ");

        switch (odpowiedz)
        {
        case 1:
            wypisz(modulo(liczby), "Po sprawdzeniu podzielnosci: ");
            break;
        
        case 2:
            wypisz(zakres(liczby), "Po sprawdzeniu zakresu: ");
            break;
        case 3:
            exit(0);
            break;

        default:
            break;
        }
    }
}