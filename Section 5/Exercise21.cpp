// Zadanie 21. Zdefinuj punkt w czasie dotyczacy twoich urodzin (zalozmy ze czas urodzenia w sekundach i minutach jest 00).
// Mozesz zaimplementowac mechanike wprowadzenia daty. Następnie znajdz roznice pomiedzy czasem twoich urodzin a obecnym czasem 
// i wypisz je. Po czym wprowadz inny punkt w czasie (niech to beda urodziny Bill'a Gates'a) i znajdz ta roznice.
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

using year = duration<int, ratio<31556952>>;
using month = duration<int64_t, ratio<2629746>>;
using day = duration<int, ratio<3600 * 24>>;



system_clock::time_point oblicz_na_time_point(int dzien, int miesiac, int rok)
{
    system_clock::time_point tp;
    tp += day(dzien - 1);
    tp += month(miesiac - 1);
    tp += year(rok - 1970);

    tp -= tp.time_since_epoch() % hours(24);
    tp -= tp.time_since_epoch() % minutes(60);
    tp -= tp.time_since_epoch() % seconds(60);

    return tp;
}

void wypisz_dlugosc(duration<int64_t, nano> okres)
{
    cout << "Od tamtej pory minelo: " << duration_cast<year>(okres).count() << " lat, " << duration_cast<month>(okres % year(1)).count() << " miesiecy, "
        << duration_cast<day>(okres % month(1)).count() << " dni, " << duration_cast<hours>(okres % day(1)).count() << " godzin, "
        << duration_cast<minutes>(okres % hours(1)).count() << " minut, " << duration_cast<seconds>(okres % minutes(1)).count() << " sekund." << endl;
}



void wprowadzenie(int &dzien, int &miesiac, int &rok)
{
    cout << "Wprowadz date (w postaci 01.01.2000): ";
    char znak;
    cin >> dzien >> znak;
    cin >> miesiac >> znak;
    cin >> rok;
}

int main()
{
    int dzien;
    int miesiac;
    int rok;

    wprowadzenie(dzien, miesiac, rok);

    //Punkt urodzin ustawiony na 00:00:00
    system_clock::time_point tp = oblicz_na_time_point(dzien, miesiac, rok);

    auto diff = system_clock::now() - tp;
    wypisz_dlugosc(diff);

    cout << "Teraz Billa Gates'a: 28.10.1955" << endl;
    dzien = 28;
    miesiac = 10;
    rok = 1955;

    tp = oblicz_na_time_point(dzien, miesiac, rok);
    diff = system_clock::now() - tp;
    wypisz_dlugosc(diff);
}