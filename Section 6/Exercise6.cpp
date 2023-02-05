// Zadanie 6 - Deszyfrator. Dostaleś kontener typu map, w ktorym umieszczone zostały liczby i odpowiadajace nim litery. Twoim zadaniem jest roszyfrowanie zapisu liczbowego podanego w postaci ciagu
// liczb na odpowiadajacy tym liczbom tekst: 0102343560189. Zeby wykonac to zadanie, uzyj iteratora operujacego na lancuhcach znakow (string).
#include <map>
#include <iostream>
using namespace std;
//****************************************************************************************************************************************************************

map<int, char> lista_deszyfratora = {{0, 'a'},
                                     {6, 'i'},
                                     {5, 'p'},
                                     {2, 'k'},
                                     {4, 'o'},
                                     {8, 'e'},
                                     {1, 't'},
                                     {3, ' '},
                                     {9, 'j'}};

int main()
{
    string szyfr = "0102343560189";
    string::const_iterator pos = szyfr.begin();
    string odpowiedz;

    cout << "Podany szyfr: " << szyfr << endl;

    while(pos != szyfr.end())
    {
        int liczba = *pos - '0';
        odpowiedz += lista_deszyfratora[liczba];
        pos++;
    }

    cout << "Rozszyfrowany szyfr: " << odpowiedz << endl;
}