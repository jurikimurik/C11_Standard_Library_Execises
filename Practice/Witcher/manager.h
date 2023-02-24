#include <vector>
#include "dice.h"
#include "player.h"
//************************************************************************************************************************
class GameManager
{
    private:
        std::vector<Player> gracze;
        int ilosc_rund = 0;

    public:
        void rozpocznij_gre();
        void zacznij_kolejna_runde();
        void wypisz_wyniki();
};