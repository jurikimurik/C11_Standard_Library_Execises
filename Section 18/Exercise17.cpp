// Zadanie 17 - Niebezpieczna maszyna parowa. Maszynę parowa obsługuje w tym samym czasie kilka pracownikow, którzy przez jakiś czas 
// ciagle zmieniają różne ustawienia maszyny parowej. W różnych odstępach czasu wypisuj jak zmieniają się jej zmienne. W końcu po 
// jakimś czasie musi wybuchnąć a pracownicy uciec.
#include <atomic>
#include <future>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>
#include <vector>
#include <iostream>
using namespace std;

atomic<int> czyJest(10);

struct MaszynaParowa {
        atomic<bool> czyDziala{true};

        atomic<int> cisnienie{100};

        atomic<double> ilosc_pary{24.4};

        atomic<double> kolidacja{2.3};
};

void pracownik(string imie, MaszynaParowa& maszyna)
{
        default_random_engine dre(imie.size() + imie.at(0));
        uniform_int_distribution id(1, 5);
        uniform_real_distribution<double> idR(1, 5);
        cout << "Jestem " << imie << "! Zaczynam prace..." << endl
             << flush;

        while(maszyna.czyDziala == true)
        {
            if(id(dre) % 2 == 0)
            {
                maszyna.cisnienie += id(dre);
            }

            if (id(dre) % 2 == 0)
            {
                maszyna.ilosc_pary.store(idR(dre) + maszyna.ilosc_pary.load());
            }

            if (id(dre) % 2 == 0)
            {
                maszyna.kolidacja.store(idR(dre) + maszyna.kolidacja.load());
            }

            if (id(dre) % 2 == 0)
            {
                maszyna.cisnienie += id(dre);
            }

            this_thread::sleep_for(chrono::milliseconds(id(dre) * 100));
        }

        cout << imie << " ucieka w pospiechu!" << endl
             << flush;
}

int main()
{
        MaszynaParowa maszyna;

        auto f1 = async(pracownik, "Marek", ref(maszyna));
        auto f2 = async(pracownik, "Marcinek", ref(maszyna));
        auto f3 = async(pracownik, "Wladimir", ref(maszyna));

        this_thread::sleep_for(chrono::seconds(2));
        auto czas_koniec = chrono::system_clock::now() + chrono::seconds(10);
        while(chrono::system_clock::now() < czas_koniec)
        {
            cout << "Cisnienie: " << maszyna.cisnienie << endl
                 << "Ilosc pary: " << maszyna.ilosc_pary << endl
                 << "Kolidacja: " << maszyna.kolidacja << endl
                 << flush;
            this_thread::yield;
            this_thread::sleep_for(chrono::seconds(5));
        }
        maszyna.czyDziala.store(false);
        cout << "Maszyna wybucha!" << endl
             << flush;

        f1.get();
        f2.get();
        f3.get();
}