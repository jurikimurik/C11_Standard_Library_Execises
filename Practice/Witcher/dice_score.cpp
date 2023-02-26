#include "dice_score.h"
using namespace std;
//************************************************************************************************
Dice_Score::Dice_Score(int generacja = 6)
{

}
//************************************************************************************************
int Dice_Score::daj_wynik(rodzaj_kontenera koscie)
{
    auto pos = nagrody.find(koscie);
    if(pos != nagrody.end())
        return pos->second;
    else
        return 0;
}

//************************************************************************************************
string Dice_Score::daj_nazwe_wyniku(rodzaj_kontenera koscie)
{
    auto pos = nazwa_nagrody.find(koscie);
    if(pos != nagrody.end())
        return pos->second;
    else
        return "Nic";
}