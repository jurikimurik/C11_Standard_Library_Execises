#ifndef MANAGER
#define MANAGER

#include <vector>
#include "player.h"
#include "util.h"
#include "dice_score.h"
#include <iostream>
#include <functional>
#include "screen.h"
#include "label.h"
//***********************************************************************************************
using wskazniki_na_funkcje = std::vector<void (Player::*)()>;
//-----------------------------------------------|||||||||---------------------------------------
using para_funkcjaGracza_opisFunkcji = std::pair<wskazniki_na_funkcje, std::vector<std::string>>;
//************************************************************************************************************************
class GameManager
{
    private:
        Screen ekran = Screen(100, 25);

        std::vector<Player> gracze;
        int ilosc_rund = 0;
        int ilosc_rund_do_wygranej = 10;
        Dice_Score sprawdzac_wynikow;

        std::vector<Dice> przechowalnia_kosci;
        std::vector<Label> przechowalnia_napisow;

    public:
        void rozpocznij_gre();
        void zacznij_kolejna_runde();
        void wyniki();
        void ruch_gracza(Player &gracz);
        void ruch_komputera(Player& gracz);
        auto daj_dzialania(Player &gracz);
        void koniec_i_zwyciezca(const Player &gracz);
        void wypisz_dzialania(para_funkcjaGracza_opisFunkcji para);
        void wypisz_wynik_rzutu(const Player &gracz);

        void daj_do_przechowalni_i_ekranu(Dice kosc);
        void daj_do_przechowalni_i_ekranu(Label napis);

        Dice& wez_z_przechowalni_kosc(int index);
        Label& wez_z_przechowalni_napis(int index);

        // Jezeli -1 to wszystko
        void usun_z_przechowalni(int index);

        template<typename T>
        T wprowadzenie(const Text_Object& obj);
};

#endif