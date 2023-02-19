// Zadanie 1 - Sortowanie Skrzyń. Stworz wlasny typ reprezentujacy skrzynie a nastepnie stworz kontener STL typu set, gdzie zaladujesz kilka takich skrzyn oraz przekazesz kryterium sortowania w postaci
// obiektu funkcyjnego, zeby set prawidlowo posortowal skrzynie. (Moga byc od najlzejszej do najciezszej)
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////
class Skrzynia
{
    public:
        int waga;
        double ilosc_zlota;

        Skrzynia(int w, double i) : waga(w), ilosc_zlota(i) {}
};

ostream &operator<<(ostream &strm, const Skrzynia& sk)
{
        strm << sk.waga << " - " << sk.ilosc_zlota;
        return strm;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
class SkrzyniaSortowanie
{
    public:
    bool operator() (const Skrzynia& s1, const Skrzynia& s2) const
    {
        return s1.waga < s2.waga;
    }
};
//**************************************************************************************************
int main()
{
    set<Skrzynia, SkrzyniaSortowanie> skladSkrzyn;

    Skrzynia barbosa(1, 20);
    Skrzynia piracka(10, 1000);
    Skrzynia aleksanda(100, 10);

    skladSkrzyn.insert(aleksanda);
    skladSkrzyn.insert(barbosa);
    skladSkrzyn.insert(piracka);
    

    for(const auto& elem : skladSkrzyn)
    {
        cout << elem << ", " << endl;
    }
    cout << endl;
}