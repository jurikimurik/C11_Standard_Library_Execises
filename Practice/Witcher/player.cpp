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
void Player::rzucz_kosci()
{
    Dice_Roller randomizator;
    for(auto& elem : koscie_gracza)
    {
        randomizator(elem);
    }
}
//***************************************************************************************************************
void Player::przerzut_okreslonych()
{
    
}