// Zadanie 1. Stworz kontener znakow typu deque z poczatkowymi znakami "Mako". Nastepnie dopisz za pomoca znakow na poczatek konteneru "Yurii ", a na koniec: "vskyi"
#include <deque>
#include <iostream>
using namespace std;
//******************************************************************************************************************************************
int main()
{
    deque<char> kontener = {'M', 'a', 'k', 'o'};

    for (string slowo = " iiruY"; auto& elem : slowo) {
        kontener.push_front(elem);
    }

    for (string slowo = "vskyi"; auto& elem : slowo) {
        kontener.push_back(elem);
    }

    for(const auto& elem : kontener) {
        cout << elem;
    }
    cout << endl;
}