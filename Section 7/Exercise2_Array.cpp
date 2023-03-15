// Zadanie 2 - Inwentarz. Kontener array<string, x> posiada okreslona liczbe elementow ekwipunku. Posortuj kazdy z tych elementow, wyrzuc niepotrzebne (z przypisem "smiecie") a zamiast nich spytaj 
//sie uzytknownika na jaki przedmiot chce wymeinic kazdy smietnik. Umozliw mu to. Nastepnie przetestuj dzialanie programu.
#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
//*******************************************************************************************************************************************************************************************************
array<string, 10> inwentarz = {"plecak", "telefon", "pomarancza", "puszka", "ksiazka", "pistolet", "zegarek", "zeszyt", "dlugopis", "notebook"};
//*******************************************************************************************************************************************************************************************************
int main()
{
    srand(time(NULL));
    for (int i = rand() % 10; i > 0; --i) {
        int losowa = rand() % 10;
        if (inwentarz[losowa].find("(smiecie)") == string::npos)
        {
            inwentarz[losowa] += "(smiecie)";
        }
    }

    for(const auto& elem : inwentarz) {
        cout << elem << ", ";
    }
    cout << endl;

    for(auto &elem : inwentarz) {
        if(elem.find("smiecie") != string::npos) {
            cout << "Wymien " << elem << " na cos innego: ";
            string str;
            cin >> str;
            elem = str;
        }
    }

    for (const auto &elem : inwentarz)
    {
        cout << elem << ", ";
    }
    cout << endl;
}