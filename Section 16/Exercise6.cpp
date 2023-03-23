// Zadanie 6 - . Niech uzytkownik poda date w rodzaju "%A %B %d" (w jezyku angielskim). Nastepnie ustawi teleportacje czasową podając lata,
// po czym "przeniesie sie w czasie" ma tą liczbe lat i program wypisze czas w postaci "%d/%m/%Y" oraz gratulacje w zwiazku z udanym skokiem
// w jedna strone!
#include <locale>
#include <ctime>
#include <iterator>
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Podaj date w stylu <Nazwa dnia tygodnia> <Nazwa miesiaca> <Dzien miesiaca> <Rok>: ";
    string format = "%A %B %d %Y";
    struct tm val = {0};
    cin >> get_time(&val, format.c_str());
    if(!cin)
    {
        cout << "Niepoprawna data!" << endl;
        return 0;
    }
    auto punkt_czasowy = chrono::system_clock::from_time_t(mktime(&val));

    cout << "Ustaw ilosc lat: ";
    size_t ilosc_lat;
    cin >> ilosc_lat;

    auto nowy_punkt_czasowy_sys_clock = punkt_czasowy + chrono::hours(8760*ilosc_lat);
    time_t nowy_punkt_czasowy = chrono::system_clock::to_time_t(nowy_punkt_czasowy_sys_clock);
    tm *nowyTM = localtime(&nowy_punkt_czasowy);

    string nowy_format = "%d/%m/%Y";
    cout << "Kongratulacje! Okazales sie w: " << put_time(nowyTM, nowy_format.c_str()) << " powodzenia wrocic z powrotem! *PUFFFfff...*" << endl;
}