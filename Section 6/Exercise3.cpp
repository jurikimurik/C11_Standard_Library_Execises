// Zadanie 3. Stworz list i nazwij go ksiazkaMikolaja i "wpisz" do niej imiona: "Igor", "Wladyslaw", "Agata", "Paulina", "Jurek", "Maks", "Andrzej". Po czym stworz nieuporzadkowany kontener dowolengo typu
// grzecznych dzieci z wartosciami "Wladyslaw", "Paulina", "Jurek", "Maks", "Andrzej". Po kolei sprawdz kadego z tej listy kto jest dzieckiem grzecznym a kto nie i wypisz stosowny komunikat na ekranie.
#include <unordered_set>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<string> ksiazkaMikolaja = {"Igor", "Wladyslaw", "Agata", "Paulina", "Jurek", "Maks", "Andrzej"};
    unordered_set<string> grzeczeDzieci = {"Wladyslaw", "Paulina", "Jurek", "Maks", "Andrzej"};

    while(!ksiazkaMikolaja.empty()) {
        //Sprawdzamy dziecko wsrod grezcznych
        string dziecko = ksiazkaMikolaja.front();

        if (grzeczeDzieci.count(dziecko))
        {
            cout << dziecko << " jest grzeczny!" << endl;
        } else {
            cout << dziecko << " nie ma na liscie grzecznych! Jest niegrzeczny!" << endl;
        }

        ksiazkaMikolaja.pop_front();
    }
}