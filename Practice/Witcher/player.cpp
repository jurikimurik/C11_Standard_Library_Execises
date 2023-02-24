#include <iostream>
#include "player.h"
using namespace std;
//***************************************************************************************************************
ostream& operator<< (ostream& strm, Player& gracz)
{
    cout << "Gracz o imieniu:" << gracz.daj_imie() << ", posiada tyle kosci: " << gracz.ilosc_kosci << endl;
    return strm;
}
//***************************************************************************************************************