// Zadanie 4 - Strumienie plikowe.Niech strumien wczytuje plik w którym są same liczbę i jedna litera.Ustaw go tak, by podczas błędu 
// rzucał wyjątek.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream strm("liczby.data");
    strm.exceptions(ios_base::failbit);

    try
    {
        while(strm)
        {
            cout << "Ladujemy liczbe..." << endl;
            string strm_napis;
            int liczba;
            strm >> liczba;
        }
    }
    catch (...)
    {
        cout << "Zadzialalo! Brawo!";
    }
}