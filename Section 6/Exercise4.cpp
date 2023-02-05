// Zadanie 4. Stworz kontener deque z nazwami twoich pobliskich miast, niech ich bedzie 5. Nastepnie wypisz te wszystkie nazwy uzywajac iteratora const. Po czym stworz zwykly iterator, ktory bedzie ustawiony
// na losowe wybrane miasto i doda przed tym miastem nadpis "Megapolis ".
#include <deque>
#include <set>
#include <iostream>
using namespace std;
//************************************************************************************************************************************************************************
int main()
{
    deque<string> miasta = {"Wejherowo", "Gdynia", "Sopot", "Gdansk", "Pruszcz Gdanski"};

    for (auto iterator = miasta.cbegin(); iterator != miasta.cend(); ++iterator) {
        cout << *iterator << ' ';
    }
    cout << endl;

    deque<string>::iterator zwykly_it = miasta.begin();
    for (int i = 0, los = rand() % 5 + 1; i < los; i++)
    {
        zwykly_it++;
    }

    *zwykly_it = string("Megapolis ") + *zwykly_it;

    for(const auto& elem : miasta) {
        cout << elem << ' ';
    }
    cout << endl;
}