// Zadanie 20. Stworz program, w ktory wprowadzisz okres czasu i wybierzesz jednostke czasu. Nastepnie, zapiszesz jednostke czasu w roznych
// postaciach i sformatujesz do postaci d:hh:mm:ss:nss
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

using days = duration<int, ratio<60 * 60 * 24>>;

int main()
{
    cout << "Wprowadz ilosc czasu: ";
    int czas;
    cin >> czas;

    cout << "Wybierz jednastke czasu: d - dni, h - godziny, m - minuty, s - sekundy, n - nanosekundy. ";
    char znak;
    cin >> znak;

    //Tylko zakladamy
    nanoseconds czas_prawdziwy(0);
    using n_t = decltype(czas_prawdziwy);



    switch (znak)
    {
    case 'd':
        czas_prawdziwy = duration_cast<n_t>(days(czas));
        break;
    case 'h':
        czas_prawdziwy = duration_cast<n_t>(hours(czas));
        break;
    case 'm':
        czas_prawdziwy = duration_cast<n_t>(minutes(czas));
        break;
    case 's':
        czas_prawdziwy = duration_cast<n_t>(seconds(czas));
        break;
    case 'n':
        czas_prawdziwy = nanoseconds(czas);
        break;

    default:
        cout << "Zla opcja. Wybieram typ jednostki: sekundy. " << endl;
        czas_prawdziwy = duration_cast<n_t>(seconds(czas));
        break;
    }

    

    days Dni = duration_cast<days>(czas_prawdziwy);
    hours Godziny = duration_cast<hours>(czas_prawdziwy % days(1));
    minutes Minuty = duration_cast<minutes>(czas_prawdziwy % hours(1));
    seconds Sekundy = duration_cast<seconds>(czas_prawdziwy % minutes(1));
    nanoseconds Nanosekundy = czas_prawdziwy;

    cout << Dni.count() << "::" << Godziny.count() << "::" << Minuty.count() << "::" 
    << Sekundy.count() << "::" << Nanosekundy.count() ;
}