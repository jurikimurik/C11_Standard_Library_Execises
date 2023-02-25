#include <deque>
#include <string>
////////////////////////////////////////////////////////////////////////////
enum class reprezentacja
{
    jeden = 1,
    dwa,
    trzy,
    cztery,
    piec,
    szesc
};
////////////////////////////////////////////////////////////////////////////
class Dice
{
    private:
        reprezentacja rodzaj_kosci;

        std::deque<char> visual;

    public:
        // Konstruktor domniemany z mozliwoscia losowosci
        Dice(bool losowosc = false) {}

        // Konstruktor z parametrem reprezentacji
        Dice(reprezentacja rodzaj) : rodzaj_kosci(rodzaj) {}

        // Konstruktor z parameterem typu int do reprezentacji
        Dice(int kosc) : rodzaj_kosci(static_cast<reprezentacja>(kosc)) {}

        void zmien_rodzaj(reprezentacja rodzaj)
        {
            rodzaj_kosci = rodzaj;
        }

        void zmien_rodzaj(int rodzaj) 
        {
            rodzaj_kosci = static_cast<reprezentacja>(rodzaj);
        }

        std::string daj_wizualna_reprezentacje();

        void odswiez_wizualna_reprezentacje();

        friend std::ostream &operator<<(std::ostream &strm, Dice &kosc);
};