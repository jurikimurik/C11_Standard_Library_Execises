#include <deque>
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

        std::string daj_wizualna_reprezentacje();
};