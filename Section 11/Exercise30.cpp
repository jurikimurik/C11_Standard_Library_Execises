// Zadanie 30 - Różnice. Użytkownik podaje ciąg. Następnie oblicza różnice pomiędzy każdymi jego dwoma elementami po kolei i 
// wypisuje te różnice. Dodatkowo również wypisuje wszystkie sumy częściowe.
#include "narzedzia.h"
#include <numeric>
#include <deque>
using namespace std;

int main()
{
    auto ciag = wprowadz_ciag<deque<int>>("Podaj ciag: ");

    cout << "Roznice pomeidzy elementami: ";
    adjacent_difference(ciag.begin(), ciag.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Sumy czesciowe tego ciagu: ";
    partial_sum(ciag.begin(), ciag.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}