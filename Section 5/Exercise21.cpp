// Zadanie 21. Zdefinuj punkt w czasie dotyczacy twoich urodzin (zalozmy ze czas urodzenia w sekundach i minutach jest 00).
// Mozesz zaimplementowac mechanike wprowadzenia daty. Następnie znajdz roznice pomiedzy czasem twoich urodzin a obecnym czasem 
// i wypisz je. Po czym wprowadz inny punkt w czasie (niech to beda urodziny Bill'a Gates'a) i znajdz ta roznice.
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    cout << "Wprowadz date (w postaci 01.01.2000): ";
    int dzien;
    int miesiac;
    int rok;
    cin >> dzien;
    cin >> miesiac;
    cin >> rok;

    //Znajdujemy roznice
    system_clock::time_point tp;
    time_t t = chrono::system_clock::to_time_t(tp);
    cout << ctime(&t);
    tp += hours(20);
    t = system_clock::to_time_t(tp);
    cout << ctime(&t);
}