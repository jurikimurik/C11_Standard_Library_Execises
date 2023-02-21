// Zadanie 2 - Multi-poszukiwacz. Masz zestaw n-liczb losowych. z tych liczb pozwol uzytkownikowi znalezc okreslone, według 1. podzielnosci,
// 2. zakresu, nastepnie pozwol mu usunac okreslone liczby spelniajace specjalne kryterium (jak dwa poprzednie) i rob to w kolko, poki
// uzytkownik nie bedzie chcial przestac i zaczac od nowa.
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
void wypisz(const vector<int> &liczby, string napis = "")
{
    cout << napis;

    if (!liczby.empty())
    {
        for (const auto &elem : liczby)
        {
            cout << elem << ", ";
        }
        cout << endl
             << endl;
    }
    else
    {
        cout << "BRAK LICZB" << endl;
    }
}
//************************************************************************************************************************
void wypisz_dzialania()
{
    cout << "Znajdz interesujace liczby wedlug: 1 - podzielnosci, 2 - zakresu. Wpisz 3 zeby zaczac od nowa i 4 zeby wyjsc. " << endl;
}
//************************************************************************************************************************
vector<int> modulo(const vector<int> &liczby)
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
    vector<int> kopia = liczby;

    wypisz(kopia);
    while (true)
    {
        
        wypisz_dzialania();
        int odpowiedz = pobierz_odpowiedz("Wpisz dzialanie: ");

        switch (odpowiedz)
        {
        case 1:
            kopia = modulo(kopia);
            wypisz(kopia, "Po sprawdzeniu podzielnosci: ");
            break;

        case 2:
            kopia = zakres(kopia);
            wypisz(kopia, "Po sprawdzeniu zakresu: ");
            break;
        case 3:
            kopia = liczby;
            wypisz(kopia, "Po przewroceniu: ");
            break;
        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }
}