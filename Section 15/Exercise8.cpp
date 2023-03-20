// Zadanie 8 - Spis gości. Posiadasz plik goscie.data. Odczytaj z niego dane do strumienia cout za pomocą funkcji get oraz zwykłych 
// przeciążonych funkcji operatora << dla strumieni.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream plik("goscie.data");

    if(!plik) {
        cout << "Nie udalo sie zaladowac. Abort!" << endl;
        return 0;
    }

    char znak;
    while(plik.get(znak))
    {
        cout.put(znak);
    }

    plik.clear();
    plik.seekg(0);

    cout << endl
         << endl;

    cout << plik.rdbuf() << endl;
}