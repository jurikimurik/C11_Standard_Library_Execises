// Zadanie 5 - Stary księgowy. Posiadasz zbiór tekstu, który napisał stary księgowy według starej formuły, gdzie imię i nazwisko 
// rozdzielało się symbolem -. Zamień to w ten sposób, żeby każdą osoba była w swoim pojedynczym wierszu w stylu 
// „<osoba><imię>*IMIE*</imię><nazwisko>*NAZWISKO*</nazwisko></osoba>;
#include <regex>
#include <iostream>
using namespace std;
//*****************************************************************************************************************************
int main()
{
    string zbior = "Andrzej - Sawicki\n"
    "Maksymilian - Trojanowski\n"
    "Yurii - Makovskyi\n"
    "Paulina - Zielinska\n"
    "Natalia - Rokosz\n";

    regex reg("(.*) - (.*)");

    /*sregex_token_iterator beg(zbior.cbegin(), zbior.cend(), reg, {1, 2});
    sregex_token_iterator end;
    while(beg != end)
    {
        cout << beg->str() << endl;

        beg++;
    }*/

    zbior = regex_replace(zbior, reg, "<osoba>\n\t<imie>$1</imie>\n\t<nazwisko>$2</nazwisko>\n</osoba>\n");

    cout << "Otrzymany zbior: \n"
         << zbior << endl;
}