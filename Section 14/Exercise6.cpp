// Zadanie 6 - Wybór słów. Posiadasz zbiór losowych słów. Niech użytkownik wprowadzi jaka litera ma być pierwsza a jaka trzecia. 
// Następnie niech program wypisze listę tych słów, które spełniają kryterium.
#include <regex>
#include <iostream>
#include "../narzedzia.h"
using namespace std;
//************************************************************************************************
int main()
{
    string slowa = "paragraf, stol, krzeslo, abetka, abecadlo, kalafior, ziemniak, krzeslo, krzet, kanalia";

    string litera1 = wprowadzenie<string>("Wprowadz pierwsza litere: ");
    string litera2 = wprowadzenie<string>("Wprowadz druga litere:");

    regex reg("[ \t\n,](" + litera1 + "." + litera2 + "[[:alnum:]]+)");

    smatch m;

    sregex_token_iterator beg(slowa.cbegin(), slowa.cend(), reg, {1});
    sregex_token_iterator end;

    if(beg == end)
        cout << "Brak znalezionych slow" << endl;

    while (beg != end)
    {
        cout << "Znalezione slowo: " << beg->str() << endl;
        beg++;
    }
}