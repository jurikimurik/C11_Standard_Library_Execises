// Zadanie 13 - Audiencja u Króla. Stwórz klasę Poddany, która będzie reprezentować zwykłego człowieka. Następnie kazdy z nich 
// ustawia się w kolejce i gada z królem. Wszyscy inni czekają w kolejce, a gdy jeden zostaje obsłużony, to wchodzi inny. 
// Skorzystaj ze zmiennych warunkowych.
#include <condition_variable>
#include <mutex>
#include <future>
#include <thread>
#include <random>
#include <iostream>
#include <chrono>
#include <deque>
using namespace std;

int ilosc_poddanych = 10;
mutex poddaniMutex;
bool czyPrzyjmuje = false;
condition_variable czyGotowPrzyjac;

class Poddany {
    public:
        int numer;

        Poddany(int n) : numer(n) {}

        void operator()()
        {
            {
                unique_lock<mutex> ul(poddaniMutex);
                czyGotowPrzyjac.wait(ul, []
                                     {return czyPrzyjmuje; });

                czyPrzyjmuje = false;
                cout << "Poddany " << numer << " zostaje przyjety u krola. " << endl
                     << flush;
            }
        }
};


deque<Poddany> poddani;


int main()
{
    
    deque<future<void>> futury;
    // ustaw do kolejki 10 poddanych
    for (int i = 0; i < ilosc_poddanych; ++i)
    {
        poddani.push_front(Poddany(i+1));
        futury.push_front(async(poddani.front()));
    }

    while(ilosc_poddanych > 0)
    {
        unique_lock<mutex> ul(poddaniMutex);
        cout << "Nastepny!" << endl;
        czyPrzyjmuje = true;
        ul.unlock();
        czyGotowPrzyjac.notify_one();
        this_thread::sleep_for(chrono::seconds(4));

        ilosc_poddanych--;
    }

    for(auto& elem : futury)
    {
        elem.get();
    }
}   