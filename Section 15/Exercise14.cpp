// Zadanie 14 - Pomocniki. Stwórz dwa dodatkowe strumienie związane ze strumieniem cout, tylko ze będą liczby wypisywać w postaci szesnastkowej oraz ósemkowej. 
// Niech użytkownik wprowadzi swoje liczby, które następnie trzeba będzie pokazać w dwóch innych dodatkowych postaciach użytkownikowi.
//Streambuffer
//Streamredirect
#include <iostream>
#include <vector>
#include "../narzedzia.h"
using namespace std;

int main()
{
    ostream strm_hex(cout.rdbuf());
    strm_hex << hex;

    ostream strm_oct(cout.rdbuf());
    strm_oct << oct;

    vector<int> liczby = wprowadz_ciag<vector<int>>("Wprowadzaj liczby rozdzielajac ich spacjami a nastepnie wpisz 'q': ");

    for(const auto& elem : liczby)
    {
        strm_oct << elem << " ";
        cout << elem << " ";
        strm_hex << elem << " ";

        cout << endl;
    }
}