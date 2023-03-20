// Zadanie 10 - Posiadasz folder o nazwie „wierszy”. Niech program odczyta każdy z tych wierszy i wypisze ich na ekranie, 
// rozdzielając liniami nowego wiersza.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream strm;

    int index = 1;
    while (true)
    {
        strm.open("wierszy/wiersz" + to_string(index) + ".w");
        if (!strm)
        {
            cout << "\n\tBRAK WIERSZY!" << endl;
            break;
        }

        cout << "Wierszyk numer " << index << " !" << endl
             << endl;

        cout << strm.rdbuf() << endl
             << endl;
        index++;
        strm.close();
    }
}