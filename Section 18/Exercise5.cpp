// Zadanie 5 - Trojka braci. Jeden wątek musi wygenerować zbiór liczb od 1 do 1.000.000 a następnie ustawić go w 
// kolejności losowej. Trojka braci wątków następnie musi użyć wynik działania pierwszego wątku w celu przeszukiwania: 
// w przód, w tył oraz od polowy w przód i wypisać wynik swojego działania.
#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

enum class szukaj
{
    w_przod,
    w_tyl,
    od_polowy_w_gore
};

vector<int> generuj_zbior()
{
    vector<int> liczby(1000000);
    iota(liczby.begin(), liczby.end(), 1);
    shuffle(liczby.begin(), liczby.end(), default_random_engine(time(nullptr)));

    return liczby;
}

long long przeszukaj(int szukana_liczba, szukaj jak, shared_future<vector<int>> watek_ze_zbiorem)
{
    vector<int> zbior = watek_ze_zbiorem.get();

    auto czas = chrono::system_clock::now();

    if(jak == szukaj::w_przod)
    {
        auto wsk_od = zbior.begin();
        auto wsk_do = zbior.end();

        if (find(wsk_od, wsk_do, szukana_liczba) == wsk_do)
        {
            cout << "Nie znaleziono!" << this_thread::get_id() << endl;
        }
    } else if (jak == szukaj::w_tyl) {
        auto wsk_od = zbior.rbegin();
        auto wsk_do = zbior.rend();

        if (find(wsk_od, wsk_do, szukana_liczba) == wsk_do)
        {
            cout << "Nie znaleziono!" << this_thread::get_id() << endl;
        }
    } else {
        auto wsk_od = zbior.begin();
        advance(wsk_od, zbior.size() / 2);
        auto wsk_do = zbior.end();

        if (find(wsk_od, wsk_do, szukana_liczba) == wsk_do)
        {
            cout << "Nie znaleziono!" << this_thread::get_id() << endl;
        }
    }

    return chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - czas).count();
}

int main()
{
    int szukana_liczba = 545658;

    shared_future<vector<int>> watek_zbioru = async(generuj_zbior);

    watek_zbioru.wait();

    auto w1 = async(przeszukaj, szukana_liczba, szukaj::w_przod, watek_zbioru);
    auto w2 = async(przeszukaj, szukana_liczba, szukaj::w_tyl, watek_zbioru);
    auto w3 = async(przeszukaj, szukana_liczba, szukaj::od_polowy_w_gore, watek_zbioru);

    cout << "Watek pierwszy: " << w1.get() << " mikrosekund" << endl;
    cout << "Watek drugi: " << w2.get() << " mikrosekund" << endl;
    cout << "Watek trzeci: " << w3.get() << " mikrosekund" << endl;
}
