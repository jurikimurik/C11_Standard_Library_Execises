// Zadanie 18 - Jeden uczeń w klasie ma za zadanie pilnować określony czas innych uczniów. Ci inni uczniowie, gdy nie są głowni, 
// wykonują różne przydzielone im zadania. Gdy nadrzędny uczeń wykonał robotę, opuszcza klasę. Musi to się dziać aż do chwili 
// póki nie zostanie jeden uczeń, który z klasy po prostu wyjdzie.
#include <atomic>
#include <future>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>
#include <vector>
#include <iostream>
using namespace std;

atomic<bool> czyJestGlowny(true);
mutex czyJestGlownyMutex;
condition_variable turaGlownego;
size_t ilosc_uczniow = 10;

void uczen(int numer)
{
    cout << "Jestem uczen nr. " << numer << endl
         << flush;
    bool czyBylGlownym = false;

    while(!czyBylGlownym && ilosc_uczniow > 1)
    {
        unique_lock<mutex> ul(czyJestGlownyMutex);
        while(czyJestGlowny.load() && ilosc_uczniow > 1)
        {
            cout << "Uczen nr. " << numer << " sprzata... " << endl << flush;
            this_thread::sleep_for(chrono::seconds(2));
        }
        if(ul)
        {
            czyJestGlowny.store(true);
            czyBylGlownym = true;
            cout << "Teraz uczen nr. " << numer << " jest glowny!" << endl
                 << flush;
        }
    }

    cout << "Uczen nr. " << numer << " wychodzi! " << endl
         << flush;
}

int main()
{
    vector<future<void>> uczniowie;

    for (int i = 0; i < ilosc_uczniow; ++i)
    {
        uczniowie.push_back(async(uczen, i+1));
    }

    this_thread::sleep_for(chrono::seconds(2));
    while (ilosc_uczniow > 0)
    {
        cout << "Klasa potrzebuje glownego!" << endl
             << flush;

        czyJestGlowny = false;

        this_thread::sleep_for(chrono::seconds(5));
        ilosc_uczniow--;
    }

    cout << "Nie ma wiecej innych uczniow. Mozna smialo wychodzic!" << endl
         << flush;

    for(auto& elem : uczniowie)
    {
        elem.get();
    }
}