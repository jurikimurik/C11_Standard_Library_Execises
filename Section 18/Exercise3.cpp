// Zadanie 3 - Sprawdzenie poszukiwania liczb. Posiadasz vector z liczbami od 1 do 1.000.000, który następnie zostaje w 
// kolejności losowej przemieszany. Użytkownik musi wprowadzić liczbę, która chce znaleźć. Sprawdź wyniki poszukiwań dla 
// pojedynczego wątku oraz dla kilku wątków.
#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include "../narzedzia.h"
using namespace std;

vector<int>::iterator poszukiwania(vector<int>::iterator wsk_od, vector<int>::iterator wsk_do, int liczba)
{
    auto czas_start = chrono::system_clock::now();
    cout << "Zaczynamy poszukiwania od " << *wsk_od << " i do " << *prev(wsk_do) << "!" << endl;

    auto pos = find(wsk_od, wsk_do, liczba);
    if(pos != wsk_do)
    {
        cout << "Znaleziono!" << endl;
        cout << "Zajelo to: " << chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - czas_start).count() << " mikrosekund! " << endl;
    } else {
        cout << "Nie znaleziono!" << endl;
    }

   
    return pos;
}

int main()
{
    vector<int> liczby(1000000);
    iota(liczby.begin(), liczby.end(), 1);
    shuffle(liczby.begin(), liczby.end(), default_random_engine(time(nullptr)));

    int poszukiwana_liczba = 565432;

    cout << "Robimy jednym watkiem: " << endl;
    poszukiwania(liczby.begin(), liczby.end(), poszukiwana_liczba);

    cout << "Robimy dwoma watkami: " << endl;
    auto f1 = async(poszukiwania, liczby.begin(), liczby.end() - liczby.size() / 2, poszukiwana_liczba);
    auto f2 = async(poszukiwania, liczby.end() - liczby.size() / 2, liczby.end(), poszukiwana_liczba);

    f1.get();
    f2.get();

    cout << "Robimy trzema watkami: " << endl;
    auto f1_2 = async(poszukiwania, liczby.begin(), liczby.end() - (liczby.size() / 3) * 2, poszukiwana_liczba);
    auto f2_2 = async(poszukiwania, liczby.end() - (liczby.size() / 3) * 2, liczby.end() - liczby.size() / 3, poszukiwana_liczba);
    auto f3_2 = async(poszukiwania, liczby.end() - liczby.size() / 3, liczby.end(), poszukiwana_liczba);

    f1_2.get();
    f2_2.get();
    f3_2.get();
}