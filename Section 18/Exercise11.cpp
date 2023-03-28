// Zadanie 11 - Rycerz i kowal. Rycerz przychodzi do kowala, żeby ten wykonał mu świetny miecz. Kowalowi to zajmuje pewna ilość czasu, 
// więc wysyła rycerza do karczmy. Po określonym upływie czasu, gdy miecz będzie gotowy, kowal przekazuje miecz przez posłańca a rycerz 
// wyrusza w podróż. Skorzystaj ze zmiennych warunkowych.
#include <condition_variable>
#include <mutex>
#include <future>
#include <thread>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

bool gotowoscMiecza = false;
mutex gotowoscMieczaMutex;
condition_variable czyGotowyMiecz;

void slowa(string slowa)
{
    cout << slowa << endl;
    this_thread::sleep_for(chrono::milliseconds(slowa.size() * 50));
}

void kowal() {
    lock_guard<mutex> lg(gotowoscMieczaMutex, adopt_lock);

    int ilosc_kuc = 5;
    while(ilosc_kuc > 0)
    {
        cout << " Kliknij <ENTER> by kuc! " << endl;
        cin.get();

        cout << "*BZDZEK*\n";
        ilosc_kuc--;
    }

    slowa("- Moje dzielo w koncu jest gotowe! Hej, Synku!");
    slowa("- Co ojcze?!");
    slowa("- Zanies ten miecz do rycerza w karczmie!");
    slowa("- Tak zrobie, Ojcze!");

    gotowoscMiecza = true;
    lg.~lock_guard();
    czyGotowyMiecz.notify_all();
}

void rycerz() {
    {
        unique_lock<mutex> ul(gotowoscMieczaMutex);
        czyGotowyMiecz.wait(ul, []
                            {return gotowoscMiecza; });
    }
    slowa("Chlopak wlatuje do karczmy.");
    slowa("- Rycerze! Twoj miecz!");
    slowa("- No w koncu! Moge ruszyc na szlak! Zegnaj, chlopcze!");
    slowa("Po kilku latach wiesc o Rycerzu Kalwinie rozprzestrzenila sie na wszystkie krolewstwa...");
    slowa("A szczegolnie - o jego slynnym mieczu!");
}

int main()
{
    slowa("- Jestem rycerz, a ty - kowal! Zrob mi miecz swietny, zebym smoka zgladzil! ");
    slowa("- Smoka?! A czy pieniadze masz, chlopcze?! ");
    slowa("- Pewnie! Trzymaj! *rzuca worek* ");
    slowa("- No dobra, biore sie do pracy, a ty idz odpoczywaj.");
    slowa("- Bede w karczmie \"Kudlata Swinia\"! Bywaj!");
    slowa("- Zegnaj!");

    cout << "I tak kowal wzial sie do pracy..." << endl;
    
    auto f1 = async(kowal);
    auto f2 = async(rycerz);

    f1.get();
    f2.get();
}
