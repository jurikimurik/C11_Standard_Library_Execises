// Zadanie 5 - Prosty edytor tekstu. Możesz wpisać tekst na początek, środek i koniec. Rowniez obliczyć ilość liter, ilość słów.
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class rodzaj
{
    symboli = 0,
    litery,
    slowa
};
//******************************************************************************************************************************
void wypisz(const string& tekst)
{
    cout << tekst << endl;
}
//******************************************************************************************************************************
void wypisz_dzialania()
{
    cout << "1 - wstaw tekst, 2 - ilosc symboli, 3 - ilosc liter, 4 - ilosc slow, 5 - wyjsc." << endl;
}
//******************************************************************************************************************************
string pobierz_tekst(string napis)
{
    cout << napis;
    string tekst;
    getline((cin >> ws), tekst);
    return tekst;
}
//******************************************************************************************************************************
int pobierz_odpowiedz(string napis)
{
    cout << napis;
    int odp;
    cin >> odp;
    return odp;
}
//******************************************************************************************************************************
void wstaw_tekst(string& tekst)
{
    cout << "1 - poczatek, 2 - srodek, 3 - koniec. " << endl;
    int odpowiedz = pobierz_odpowiedz("Wybierz gdzie: ");

    auto pos = tekst.begin();
    if(odpowiedz == 2)
        advance(pos, tekst.size() / 2);
    else if(odpowiedz == 3)
        pos = tekst.end();

    string jaki_tekst = pobierz_tekst("Wpisz tekst: ");

    tekst.insert(pos, jaki_tekst.begin(), jaki_tekst.end());
}
//******************************************************************************************************************************
void ilosc(const string& tekst, rodzaj jaki)
{
    int ilosc = 0;
    string info = "Ilosc ";

    if(jaki == rodzaj::symboli)
    {
        ilosc = tekst.size();
        info += " symboli";
    } else if (jaki == rodzaj::litery)
    {
        ilosc = count_if(tekst.cbegin(), tekst.cend(), [](char c)
                         { return isalpha(c); });
        info += " liter";
    } else {

        string kopia(tekst);
        replace_if(
            kopia.begin(), kopia.end(), [](char c)
            { return !isalpha(c); },
            ' ');

        stringstream strm (kopia);
        while(strm)
        {
            string slowo;
            strm >> slowo;
            ilosc++;
        }
        ilosc--;

        info += " slow";
    }

    info += ": " + to_string(ilosc);
    wypisz(info);
}
//******************************************************************************************************************************
int main()
{
    string tekst = pobierz_tekst("Wpisz poczatkowy tekst: ");

    while(true)
    {
        wypisz(tekst);
        wypisz_dzialania();
        int odpowiedz = pobierz_odpowiedz("Wybierz dzialanie: ");
        switch (odpowiedz)
        {
        case 1:
            wstaw_tekst(tekst);
            break;
        case 2:
            ilosc(tekst, rodzaj::symboli);
            break;
        case 3:
            ilosc(tekst, rodzaj::litery);
            break;
        case 4:
            ilosc(tekst, rodzaj::slowa);
            break;
        case 5:
            exit(0);
            break;

        default:
            break;
        }
    }
}