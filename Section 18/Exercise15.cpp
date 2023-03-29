// Zadanie 15 - Zupa dla żołnierzy. Kilka żołnierzy czekają na zupę w kuchni. Mogą się pomiędzy sobą bić i się przeciskać, 
// ale na jednego żołnierza przysługuje tylko jedna miska zupy po czym ten musi wyjść z kolejki.
#include <atomic>
#include <future>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>
#include <iostream>
using namespace std;

atomic<bool> czyJestZupa;
mutex czyJestZupaMutex;
condition_variable dzwonekDoZupy;

void zolnierz_w_kolejce(string imie)
{
    cout << "Jestem " << imie << ", czekam na zupe!" << endl
         << flush;
    bool czyMaZupe = false;

    while(!czyMaZupe)
    {
        unique_lock<mutex> ul(czyJestZupaMutex, adopt_lock);
        dzwonekDoZupy.wait(ul, []
                           { return czyJestZupa.load(); });
        if (ul)
        {
            czyJestZupa.store(false);
            cout << imie << " zabral sobie zupe i jest zadowolony!" << endl
                 << flush;
            czyMaZupe = true;
        }
    }
}

int main()
{
    auto f1 = async(zolnierz_w_kolejce, "Witek");
    auto f2 = async(zolnierz_w_kolejce, "Arnold");
    auto f3 = async(zolnierz_w_kolejce, "Kolya");
    auto f4 = async(zolnierz_w_kolejce, "Wladyslaw");
    auto f5 = async(zolnierz_w_kolejce, "Ignacy");

    int ilosc_porcji = 5;
    while(ilosc_porcji > 0)
    {
        cout << "Babcia Olga przygotowuje zupe..." << endl
             << flush;

        this_thread::sleep_for(chrono::seconds(5));
        cout << "- Zupa gotowa! *BDZIEK*" << endl
             << flush;

        czyJestZupa.store(true);
        dzwonekDoZupy.notify_all();
        this_thread::sleep_for(chrono::seconds(2));
        ilosc_porcji--;
    }

    f1.get();
    f2.get();
    f3.get();
    f4.get();
    f5.get();
}