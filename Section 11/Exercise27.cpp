// Zadanie 27 - Ultra-poszukiwacz. Niech użytkownik wprowadzi dwa ciągi. Posortuj je. Pozwól mu sprawdzić wspólne elementy, połączone 
// elementy, różnice i różnice symetryczna.
#include "narzedzia.h"
#include <deque>
using namespace std;


int main()
{
    auto ciag_pierwszy = wprowadz_ciag<deque<int>>("Wprowadz pierwszy ciag: ");
    sort(ciag_pierwszy.begin(), ciag_pierwszy.end());

    auto ciag_drugi = wprowadz_ciag<deque<int>>("Wprowadz ciag drugi: ");
    sort(ciag_drugi.begin(), ciag_drugi.end());

    while(true)
    {
        drukuj(ciag_pierwszy, "Pierwszy: ", "\n");
        drukuj(ciag_drugi, "Drugi: ", "\n");

        int odpowiedz = wprowadzenie<int>("1 - polaczone elementy, 2 - wspolne elementy, 3 - roznice, 4 - roznice symetryczne, 5 - wyjscie: ");

        switch (odpowiedz)
        {
        case 1:
            cout << "Polaczone: ";
            set_intersection(ciag_pierwszy.begin(), ciag_pierwszy.end(), ciag_drugi.begin(), ciag_drugi.end(), ostream_iterator<int>(cout, ", "));
            cout << endl;
            break;
        case 2:
            cout << "Wspolne: ";
            set_union(ciag_pierwszy.begin(), ciag_pierwszy.end(), ciag_drugi.begin(), ciag_drugi.end(), ostream_iterator<int>(cout, ", "));
            cout << endl;
            break;
        case 3:
            cout << "Roznice: ";
            set_difference(ciag_pierwszy.begin(), ciag_pierwszy.end(), ciag_drugi.begin(), ciag_drugi.end(), ostream_iterator<int>(cout, ", "));
            cout << endl;
            break;
        case 4:
            cout << "Roznica symetryczna: ";
            set_symmetric_difference(ciag_pierwszy.begin(), ciag_pierwszy.end(), ciag_drugi.begin(), ciag_drugi.end(), ostream_iterator<int>(cout, ", "));
            cout << endl;
            break;
        case 5:
            exit(0);
            break;

        default:
            break;
        }

        cout << endl;
    }
}