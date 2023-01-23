/*Zadanie12. Stworz szablon funkcji wywolywanej na rzecz jakiegos typu, ktory wypisze dla kazdego z podanego typu nastepujace parametry: is_signed, is_integer,
is_bounded, is_modulo, min(), max(), digits, has_infinity(i jesli ma to infinity()), has_quiet_NaN(i jesli ma has_singnaling_NaN), has_denorm. d*/
#include <iostream>
#include <limits>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
ostream & wypisz_charakterystyki(ostream & strm)
{
    strm << endl
         << endl;

    strm << boolalpha; 

    strm << "Typ ze znakiem? " << numeric_limits<T>::is_signed << endl;

    strm << "Typ calkowity? " << numeric_limits<T>::is_integer << endl;

    strm << "Jest skonczony? " << numeric_limits<T>::is_bounded << endl;

    strm << "Przy dodaniu moze dac mniejsza? " << numeric_limits<T>::is_modulo << endl;

    strm << "Minimalna: " << numeric_limits<T>::min() << endl;

    strm << "Maksymalna: " << numeric_limits<T>::max() << endl;

    strm << "Liczba bitow: " << numeric_limits<T>::digits << endl;

    strm << "Dodatnia nieskonczonosc jest? " << numeric_limits<T>::has_infinity << endl;
    if(numeric_limits<T>::has_infinity == true)
        strm << "Nieksonczonosc: " << numeric_limits<T>::infinity() << endl;

    strm << "Niesygnalizowana wartosc nieliczbowa? " << numeric_limits<T>::has_quiet_NaN << endl;
    if(numeric_limits<T>::has_quiet_NaN == true)
        strm << "Reprezentacja NaN? " << numeric_limits<T>::has_signaling_NaN << endl;

    strm << "Wartosci zdenormalizowane? " << numeric_limits<T>::has_denorm << endl;

    strm << endl
         << endl;

    return strm;
}
//************************************************************************************************************************************************************************************
int main()
{
    cout << "Char: ";
    wypisz_charakterystyki<char>(cout);

    cout << "String: ";
    wypisz_charakterystyki<string>(cout);

    cout << "uint64_t: ";
    wypisz_charakterystyki<uint64_t>(cout);

    cout << "Double: ";
    wypisz_charakterystyki<double>(cout);
}