#include <list>
#include <string>
#include "dice.h"
////////////////////////////////////////////////////////////////////////////
class Player
{
    private:
        std::string nazwa_gracza;
        bool czy_komputer;
        std::list<Dice> koscie_gracza;

    public:
        // Konstruktor domniemany tworzy komputerowego gracza
        Player() : czy_komputer(true), nazwa_gracza("Przeciwnik") {}

        //Konstruktor sparametryzowany tworzy zwyklego gracza
        Player(std::string imie, bool czy_k) : nazwa_gracza(imie), czy_komputer(czy_k) {}

        auto daj_imie()
        {
            return nazwa_gracza;
        }

        void ustaw_imie(std::string imie)
        {
            nazwa_gracza = imie;
        }

        bool czy_jest_komputerem()
        {
            return czy_komputer;
        }

        auto daj_koscie()
        {
            return koscie_gracza;
        }
};