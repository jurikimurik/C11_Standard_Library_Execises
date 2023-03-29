// Zadanie 14 - Zliczanie cywili. Kilka żołnierzy muszą zliczyć wiele cywili (do 10000) i wpisywać ich ilość do jednego dokumentu. 
// Muszą to robić po kolei bo inaczej się pogubią.
#include <atomic>
#include <future>
#include <mutex>
#include <chrono>
#include <random>
#include <iostream>
using namespace std;

atomic<long double> ilosc_cywili;

void zliczaj_zolnierzu(string imie)
{
    cout << "Jestem " << imie << " zaczynam zliczac!" << flush << endl;
    default_random_engine dre(imie.size() + imie.at(0));
    uniform_int_distribution id(100, 200);

    while (ilosc_cywili.load() < 10000)
    {
        ilosc_cywili.store(ilosc_cywili + id(dre));
        this_thread::sleep_for(chrono::milliseconds(id(dre) * 2));
    }

    cout << imie << ", prace skonczylem!" << endl
         << flush;
}

int main()
{
    auto f1 = async(zliczaj_zolnierzu, "Jacek");
    auto f2 = async(zliczaj_zolnierzu, "Witold");
    auto f3 = async(zliczaj_zolnierzu, "Cezary");

    while (ilosc_cywili.load() < 10000)
    {
        cout << "Juz zliczono: " << ilosc_cywili.load() << endl
             << flush;
        this_thread::yield();
        this_thread::sleep_for(chrono::seconds(2));
    }

    cout << "Policzone! Ilosc cywili: " << ilosc_cywili.load() << endl;

    f1.get();
    f2.get();
    f3.get();
}