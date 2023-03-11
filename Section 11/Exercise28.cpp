// Zadanie 28 - Liczymy ciąg. Użytkownik podaje ciąg. Następnie wybiera czy mamy dodać do siebie wszystkie jego elementy czy odjąć i 
// wypisuje rezultat na ekranie.
#include "narzedzia.h"
#include <numeric>
#include <deque>

int main()
{
    auto ciag = wprowadz_ciag<deque<int>>("Wprowadz ciag liczb: ");

    int odpowiedz = wprowadzenie<int>("Chcesz ich wszystkie 1 - dodac czy 0 - odjac od siebie? ");

    if(odpowiedz) {
        cout << accumulate(ciag.begin(), ciag.end(), 0) << endl;
    }
    else
    {
        cout << accumulate(ciag.begin(), ciag.end(), 0, minus<int>()) << endl;
    }
}