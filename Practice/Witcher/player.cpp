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
void Player::rzucz_kosci(list<int> jakie_do_przerzutu)
{
    Dice_Roller randomizator;
    for (const auto &elem : jakie_do_przerzutu)
    {
        auto pos = koscie_gracza.begin();
        advance(pos, elem - 1);
        randomizator(*pos);
    }
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

    list<int> jakie_przerzucic;
    cout << "Wprowadz jakie chcesz przerzucic podajac ich indeksy (od 1 do " << koscie_gracza.size() << ") i "
         << "rodzelajac spacjami. Na koniec wpisz dowolna litere." << endl;
    
    while(cin)
    {
        int odpowiedz = wprowadzenie<int>();
        jakie_przerzucic.push_back(odpowiedz);
    }
    jakie_przerzucic.pop_back();
    cin.clear();
    cin.ignore();

    rzucz_kosci(jakie_przerzucic);
}
//***************************************************************************************************************
void Player::przerzut_okreslonych(list<int> &ktore)
{
    rzucz_kosci(ktore);
}