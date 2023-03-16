// Zadanie 4 - Podejrzani. Posiadasz długi zbiór imion i nazwisk. Używając iteratorów tokenów, znajdź osoby, których imiona 
// zaczynaja się na P i nazwiska zaczynaja się na A. Wypisz je i określ ich jako podejrzanych.

#include <regex>
#include <iostream>
using namespace std;

int main()
{
    string imiona_i_nazwiska = " Lolek Bolek, Stanislaw Kaczynski, Boleslaw Prus, Panel Alfred, Adolf Respublika, Pawel Alwares";

    regex reg("[ \t\n,](P[a-zA-Z]+ A[a-zA-Z]+)");

    sregex_iterator beg(imiona_i_nazwiska.cbegin(), imiona_i_nazwiska.cend(), reg);
    sregex_iterator end;
    for_each(beg, end, [] (const smatch& m) {
        cout << "Podejrzany: " << m.str(1) << endl;
    });
}