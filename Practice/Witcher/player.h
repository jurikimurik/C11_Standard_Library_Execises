#include <list>
#include <string>
#include <iterator>
#include "dice.h"
////////////////////////////////////////////////////////////////////////////
using rodzaj_kontenera = std::list<Dice>;
////////////////////////////////////////////////////////////////////////////
class Player
{
    private:
        std::string nazwa_gracza;
        bool czy_komputer;
        short ilosc_kosci;
        rodzaj_kontenera koscie_gracza = wez_swoje_koscie();

    public:
        // Konstruktor domniemany tworzy komputerowego gracza
        Player() : nazwa_gracza("Przeciwnik"), czy_komputer(true), ilosc_kosci(6){}

        //Konstruktor sparametryzowany tworzy zwyklego gracza
        Player(std::string imie, bool czy_k, int ilosc) : nazwa_gracza(imie), czy_komputer(czy_k), ilosc_kosci(ilosc) {}

        ///////////////////////////////////////
        auto daj_imie()
        {
            return nazwa_gracza;
        }

        ///////////////////////////////////////
        void ustaw_imie(std::string imie)
        {
            nazwa_gracza = imie;
        }

        ///////////////////////////////////////
        bool czy_jest_komputerem()
        {
            return czy_komputer;
        }

        ///////////////////////////////////////
        auto daj_koscie()
        {
            return koscie_gracza;
        }

        ///////////////////////////////////////
        void ustaw_koscie(decltype(koscie_gracza) koscie)
        {
            koscie_gracza = koscie;
        }

        ///////////////////////////////////////
        rodzaj_kontenera wez_swoje_koscie()
        {
            decltype(koscie_gracza) potrzebne_koscie;
            for (int i = 0; i < ilosc_kosci; ++i)
            {
                Dice kosc;
                potrzebne_koscie.push_back(kosc);
            }

            return potrzebne_koscie;
        }

        friend std::ostream &operator<<(std::ostream &strm, Player &gracz);
};