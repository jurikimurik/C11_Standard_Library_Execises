// Zadanie 1 - Analizator tekstu. Wczytaj plik uzytkownika o zadanej nazwie z rozszerzeniem '.tekst' i pozwol uztykownikowi: 1. posortowac tekst, 2. wypisac ilosc slow, 3. wypisac
// ilosc liter.
#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> zbior;
//******************************************************************************************************************************************************************************
string pobierz_nazwe(string tekst)
{
    cout << tekst;
    tekst.clear();

    cin >> tekst;
    return tekst; 
}
//******************************************************************************************************************************************************************************
void wypisz_zbior()
{
    for(const auto& elem : zbior)
    {
        cout << elem << " - ";
    }
    cout << endl;
}
//******************************************************************************************************************************************************************************
void wypisz_dzialania()
{
    cout << "1 - posortuj, 2 - wyznacz ilosc slow, 3 - wyznacz ilosc liter, 4 - wyjdz." << endl;
}
//******************************************************************************************************************************************************************************
bool wgraj_plik(string nazwa)
{
    nazwa += ".tekst";

    ifstream strm (nazwa);
    if(!strm)
    {
        cout << "Nie udalo sie zaladowac plik " << nazwa << ". Sprobuj ponownie. " << endl;
        return false;
    }

    while(strm)
    {
        copy(istream_iterator<string>(strm), istream_iterator<string>(), inserter(zbior, zbior.begin()));
    }
    return true;

}
//******************************************************************************************************************************************************************************
int pobierz_odpowiedz(string napis = "")
{
    cout << napis;
    int odp;
    cin >> odp;
    return odp;
}
//******************************************************************************************************************************************************************************
void sortowanie()
{
    int odpowiedz = pobierz_odpowiedz("Wybierz typ sortowania (1 - <, 2 - >): ");
    switch (odpowiedz)
    {
    case 1:
        sort(zbior.begin(), zbior.end());
        break;
    
    case 2:
        sort(zbior.begin(), zbior.end(), greater());
    
    default:
        cout << "Nie zrozumialem polecenia." << endl;
        break;
    }
}
//******************************************************************************************************************************************************************************
int ilosc_slow()
{
    vector<string> kopia(zbior);
    
    transform(kopia.begin(), kopia.end(), kopia.begin(), [] (string str) {
        str.erase(remove_if(str.begin(), str.end(), [] (char znak) {
            if(znak > 64 && znak < 91 || znak > 96 && znak < 123)
            // bo litera
                return false;
            else
                return true;
        }), str.end());
    });

    return kopia.size();
    
}
//******************************************************************************************************************************************************************************
int ilosc_liter()
{
    int ilosc = 0;
    for(const auto& elem : zbior)
    {
        int w_tym_slowie = count_if(elem.begin(), elem.end(), [] (char znak) {
            if(znak > 64 && znak < 91 || znak > 96 && znak < 123)
            // bo litera
                return false;
            else
                return true;
        });
        ilosc += w_tym_slowie;
    }

    return ilosc;
}
//******************************************************************************************************************************************************************************
int main()
{

    while(!wgraj_plik(pobierz_nazwe("Podaj nazwe pliku: ")));

    while(true)
    {
        wypisz_zbior();
        wypisz_dzialania();
        int odpowiedz = pobierz_odpowiedz("Wybierz dzialanie: ");
        switch (odpowiedz)
        {
        case 1:
            sortowanie();
            break;
        case 2:
            cout << ilosc_slow() << endl;
            break;
        case 3:
            cout << ilosc_liter() << endl;
            break;
        case 4:
            exit(0);
            break;

        
        default:
            break;
        }
    }
}