#include "dice.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Obiekt funkcyjny do losowania kosci
class Dice_Roller
{
    // Konstruktor domniemany
    Dice_Roller() {}

    // Funkcja zmieniajaca rodzaj
    void operator() (Dice& kosc)
    {
        kosc.zmien_rodzaj(static_cast<reprezentacja>(rand() % 6 + 1));
    }
};