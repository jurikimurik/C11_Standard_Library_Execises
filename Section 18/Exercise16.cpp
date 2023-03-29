// Zadanie 16 - Pudełko piłek. Kilka sportowców muszą biegać kilka razy w kółko i wrzucać do pudełka losowa ilość piłek. Gdy się uzbiera 
// wystarczającą ilość, przestają i sprawdzają czas.
#include <atomic>
#include <future>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>
#include <iostream>
using namespace std;

atomic<int> ilosc_pilek(0);
atomic<decltype(&cout)> wyjscie(&cout);

void sportowiec(string imie)
{
    default_random_engine dre(imie.size() + imie.at(0));
    uniform_int_distribution id(1, 5);
    *wyjscie << imie << " zaczyna biec!" << endl
         << flush;

    while(ilosc_pilek.load() < 100)
    {
        ilosc_pilek += id(dre);
        this_thread::sleep_for(chrono::milliseconds(id(dre) * 1000));
    }
}

int main()
{
    auto f1 = async(sportowiec, "Jazyna");
    auto f2 = async(sportowiec, "Kamil");
    auto f3 = async(sportowiec, "Alfred");

    auto czas_start = chrono::system_clock::now();

    while(ilosc_pilek.load() < 100)
    {
        *wyjscie << "W pudelku jest: " << ilosc_pilek << endl
                << flush;
        this_thread::yield();
        this_thread::sleep_for(chrono::seconds(3));
    }

    auto czas_stop = chrono::system_clock::now();
    *wyjscie << "Wystarczajaca ilosc pilek!" << endl
            << flush;

    long long sekundy = chrono::duration_cast<chrono::seconds>(czas_stop - czas_start).count();
    long long milisekundy = chrono::duration_cast<chrono::milliseconds>(czas_stop - czas_start).count() - sekundy * 1000;

    *wyjscie << "Wasz czas to " << sekundy << "s i "
            << milisekundy << " ms " << endl
            << flush;

    f1.get();
    f2.get();
    f3.get();
}