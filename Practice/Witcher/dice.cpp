#include "dice.h"
using namespace std;
//****************************************************************************************************
string Dice::daj_wizualna_reprezentacje()
{
    odswiez_wizualna_reprezentacje();

    string wizualny_tekst;

    for(const auto& elem : visual)
    {
        wizualny_tekst.push_back(elem);
    }

    return wizualny_tekst;
}
//****************************************************************************************************
void Dice::odswiez_wizualna_reprezentacje()
{
    visual.clear();

    int liczba = static_cast<int>(rodzaj_kosci);

    string tekst(to_string(liczba));
    for(const auto& elem : tekst)
    {
        visual.push_back(elem);
    }
}

//****************************************************************************************************
ostream& operator<<(ostream &strm, Dice &kosc)
{
    strm << kosc.daj_wizualna_reprezentacje();
    return strm;
}