#ifndef DICE_SCORE
#define DICE_SCORE

#include "player.h"
#include "dice.h"
#include <map>
#include <vector>
#include <algorithm>
//********************************************************************************************************************
class Dice_Score
{
    enum class rodzaj_wygranej
    {
        nic = 1,
        dwa,
        trzy,
        cztery,
        piec,
        od_1_do_5,
        od_2_do_6,
    };

    vector<string> nazwy = {
        "Nic",
        "Swieta dwojka",
        "Potezna trojka",
        "Czworka dziewic",
        "Poker",
        "Studenci",
        "Mnichowie",
    };

private:
    std::map<rodzaj_wygranej, int> nagrody;
    std::map<rodzaj_wygranej, string> nazwa_nagrody;
    int ilosc_kosci;

public:
    Dice_Score(int k = 5);

    int daj_wynik(rodzaj_kontenera koscie);
    std::string daj_nazwe_wyniku(rodzaj_kontenera koscie);
    rodzaj_wygranej jaka_wygrana(rodzaj_kontenera koscie);
    Player *u_kogo_najwiekszy(vector<const Player *> gracze_z_takimi_samymi_wynikami);
};

#endif