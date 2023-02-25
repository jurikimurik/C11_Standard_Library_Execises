#include <vector>
#include "player.h"
//***********************************************************************************************
using wskazniki_na_funkcje = std::vector<void (Player::*)()>;
//-----------------------------------------------|||||||||---------------------------------------
using para_funkcjaGracza_opisFunkcji = std::pair<wskazniki_na_funkcje, std::vector<std::string>>;
//************************************************************************************************************************
class GameManager
{
    private:
        std::vector<Player> gracze;
        int ilosc_rund = 0;

    public:
        void rozpocznij_gre();
        void zacznij_kolejna_runde();
        void wyniki();
        void ruch_gracza(Player &gracz);
        void ruch_komputera(Player& gracz);
        auto daj_dzialania(Player &gracz);
        void koniec_i_zwyciezca(const Player &gracz);
        void wypisz_dzialania(para_funkcjaGracza_opisFunkcji para);
};