#include "dice_score.h"
using namespace std;
//************************************************************************************************************************************
rodzaj_wygranej Dice_Score::jaka_wygrana(rodzaj_kontenera koscie)
{
    
}
//************************************************************************************************************************************
Dice_Score::Dice_Score(int generacja = 6)
{
    rodzaj_wygranej rodzaj = rodzaj_wygranej::nic;
    int wygrana = 0;
    auto pos = nazwy.begin();

    for(const auto& elem : nazwy)
    {
        nagrody.insert(make_pair(rodzaj, wygrana));
        nazwa_nagrody.insert(make_pair(rodzaj, *pos));

        rodzaj = static_cast<rodzaj_wygranej>(static_cast<int>(rodzaj) + 1);
        ++pos;
        wygrana += 100;
    }
}
//************************************************************************************************************************************
int Dice_Score::daj_wynik(rodzaj_kontenera koscie)
{
    rodzaj_wygranej jaki = jaka_wygrana(koscie);
    auto pos = nagrody.find(jaki);
    return pos->second;
}

//************************************************************************************************************************************
string Dice_Score::daj_nazwe_wyniku(rodzaj_kontenera koscie)
{
    rodzaj_wygranej jaki = jaka_wygrana(koscie);
    auto pos = nazwa_nagrody.find(jaki);
    return pos->second;
}