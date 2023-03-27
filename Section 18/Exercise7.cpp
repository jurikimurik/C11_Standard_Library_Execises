// Zadanie 7 - Multi-generacja haseł. W kilku różnych podstawowych wątkach 
// jednocześnie trwa generacja hasła. Zdobądź każde z tych haseł i wypisz je na ekranie.
#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

void generuj_haslo(promise<string>& p, int rand)
{
    default_random_engine rde(rand);
    uniform_int_distribution di(0, 61);

    string haslo;
    for (int i = 0; i < 10; ++i)
    {
        haslo += (di(rde)+65);
        this_thread::sleep_for(chrono::milliseconds(di(rde) * 10));
    }

    p.set_value(haslo);
    return;
}

int main()
{
    int ilosc_watkow = 10;

    vector<thread> watki;
    vector<promise<string>> obietnice(ilosc_watkow);
    for (int i = 0; i < ilosc_watkow; ++i)
    {
        watki.push_back(thread(generuj_haslo, ref(obietnice.at(i)), i+10));
    }

    for(auto& elem : watki)
    {
        elem.join();
    }

    vector<future<string>> rezultaty;
    for (int i = 0; i < ilosc_watkow; ++i)
    {
        rezultaty.push_back(obietnice.at(i).get_future());
    }

    for(auto& elem : rezultaty)
    {
        cout << "Haslo: " << elem.get() << endl;
    }
}