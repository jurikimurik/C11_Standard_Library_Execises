#include "player.h"
#include "dice.h"
#include <map>
//********************************************************************************************************************
class Dice_Score
{
    private:
        std::map<rodzaj_kontenera, int> nagrody;
        std::map<rodzaj_kontenera, string> nazwa_nagrody;

    public:
        Dice_Score(int generacja = 6);

        int daj_wynik(rodzaj_kontenera koscie);
        std::string daj_nazwe_wyniku(rodzaj_kontenera koscie);
};