/*Zadanie 11. Dla ponizszych typow: uint16_t, char, long double, string, size_t, float sprawdz czy kazdy z nich: is_integer, is_specialized, is_bounded, min(), max(),
lowest(), digits, round_style(), has_infinity, has_denorm, traps.*/
#include <iostream>
#include <limits>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void wypisz_specjalizacje()
{
    // Dla true lub false
    cout << std::boolalpha;

    cout << "Jest calkowity?\t\t\t\t\t " << numeric_limits<T>::is_integer << endl;
    cout << "Czy posiada specjalizacje?\t\t\t " << numeric_limits<T>::is_specialized << endl;
    cout << "Czy zbior wartosci jest skonczony?\t\t " << numeric_limits<T>::is_bounded << endl;
    cout << "Minimalna wartosc:\t\t\t\t " << numeric_limits<T>::min() << endl;
    cout << "Maksymalna wartosc:\t\t\t\t " << numeric_limits<T>::max() << endl;
    if constexpr(numeric_limits<T>::is_bounded == true)
        cout << "Maksymalna ujemna wartosc skonczona:\t\t " << numeric_limits<T>::lowest() << endl;
    cout << "Liczba bitow bez znaku:\t\t\t\t " << numeric_limits<T>::digits << endl;
    cout << "Typ zaokraglenia:\t\t\t\t " << numeric_limits<T>::round_style << endl;
    cout << "Czy typ posiada reprezentacje dodatniej nieskoncznosci? " << numeric_limits<T>::has_infinity << endl;
    cout << "Czy typ dopuszcza wartosci zdenormalizowane? " << numeric_limits<T>::has_denorm << endl;
    cout << "Jest pulapkowanie?\t\t\t\t " << numeric_limits<T>::traps << endl;
}
//********************************************************************************************************************************
int main()
{
    cout << "Dla uint16_t: ";
    wypisz_specjalizacje<uint16_t>();
    cout << endl;

    cout << "Dla char: ";
    wypisz_specjalizacje<char>();
    cout << endl;

    cout << "Dla long double: ";
    wypisz_specjalizacje<long double>();
    cout << endl;

    cout << "Dla string: ";
    wypisz_specjalizacje<string>();
    cout << endl;

    cout << "Dla size_t: ";
    wypisz_specjalizacje<size_t>();
    cout << endl;

    cout << "Dla float: ";
    wypisz_specjalizacje<float>();
}