#include "player.h"
#include "dice.h"
#include <map>
#include <vector>
//********************************************************************************************************************
vector<string> nazwy = {"Nic", "Swieta dwojka", "Potezna trojka", "Mnichowie", "Czworka dziewic", "Studenci", "Poker"};
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

private:
    std::map<rodzaj_wygranej, int> nagrody;
    std::map<rodzaj_wygranej, string> nazwa_nagrody;

public:
    Dice_Score(int generacja = 5);

    int daj_wynik(rodzaj_kontenera koscie);
    std::string daj_nazwe_wyniku(rodzaj_kontenera koscie);
    rodzaj_wygranej jaka_wygrana(rodzaj_konetenra koscie);
};