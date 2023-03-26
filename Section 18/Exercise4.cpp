// Zadanie 4 - Poszukiwacz pliku. Stwórz wątek, który będzie cały czas poszukiwał w działającym folderze pliku o nazwie 
// „dla_watku.txt”. Musi powtarzać swoje działanie aż dopóki go nie znajdzie i nie zapisze tam „w koncu jesteś!” po czym 
// nastąpi zamknięcie programu. (W przeciwnych sytuacjach niech wypisuje komunikat, ze na razie nie znalazł pliku).
#include <iostream>
#include <fstream>
#include <future>
#include <chrono>
#include <thread>
using namespace std;

void szukaj_pliku(string nazwa)
{
    fstream strm(nazwa);
    while (true)
    {
        strm.open(nazwa);
        if (strm)
        {
            cout << "Znalazlem! Zapisuje!" << endl;

            strm << endl
                 << "w koncu jestes!" << endl;
            break;
        } else {
            cout << "Na razie nie ma. Zasypiam na 5 sekund." << endl;
            this_thread::sleep_for(chrono::seconds(5));
            strm.clear();
        }
        strm.close();
    }
}

int main() {
    auto watek = async(szukaj_pliku, "dla_watku.txt");
    watek.get();
}