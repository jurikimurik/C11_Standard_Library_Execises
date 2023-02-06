// Zadanie 12 - Ubrania. Masz konetener osob typu deque<string>, gdzie kazdy z nich ma przydomek "Nagi". Za pomocą algorytmu i przekazanej funkcji, zmien ten przydomek u kazdej osoby na "Ubrany".
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
//*******************************************************************************************************************************************************************************

deque<string> osoby = {"Nagi Janusz",
                       "Nagi Dobromił",
                       "Nagi Janusz",
                       "Nagi Ignacy",
                       "Nagi Korneliusz",
                       "Nagi Ernest",
                       "Nagi Bruno",
                       "Nagi Eustachy",
                       "Nagi Paweł",
                       "Nagi Klaudiusz",
                       "Nagi Dorian",
                       "Nagi Leonardo",
                       "Nagi Kordian",
                       "Nagi Remigiusz",
                       "Nagi Robert",
                       "Nagi Kajetan",
                       "Nagi Natan",
                       "Nagi Miłosz",
                       "Nagi Jerzy",
                       "Nagi Gustaw"};

//*******************************************************************************************************************************************************************************

string kwatermistrz(string osoba) {
    string slowo = "Nagi ";
    string::iterator pos = osoba.begin();
    pos += osoba.find(slowo);
    osoba.erase(pos, pos + slowo.length());

    osoba = string("Ubrany ") + osoba;
    return osoba;
}

int main()
{
    for(const auto& elem : osoby) {
        cout << elem << ", ";
    }
    cout << endl;

    cout << endl
         << "Ruszamy do KWATERMISTRZA!" << endl;

    transform(osoby.begin(), osoby.end(), osoby.begin(), kwatermistrz);

    for (const auto &elem : osoby)
    {
        cout << elem << ", ";
    }
    cout << endl;
}