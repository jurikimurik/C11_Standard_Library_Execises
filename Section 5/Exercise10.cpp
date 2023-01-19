/*Zadanie 10. Stworz swoja klase Ogien z wlasnym destruktorem, ktory bedzie mowic ze ogien zostal zgaszony. Nastepnie stworz unikalny 
wskaznik, ktory bedzie nazywac sie drzewo i miescic w sobie tabele obiektow klasy ogien (niech ich bedzie 5). Utworz funkcje, ktora
nazywa sie straz_pozarna(...), ktora zgasi (usunie) wszystkie obiekty Ogien a nastepnie i zetnie (usunie) drzewo, ktore powinno bylo
juz sie nazywac spalone_drzewo. (Wczesniej zostalo zgaszone i zwrocone przez straz miejska) */

#include <iostream>
#include <memory>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////
class Ogien
{
    public:
    Ogien()
    {
        cout << "Ogien sie zapalil!" << endl;
    }

    ~Ogien()
    {
        cout << "Ogien zgasl!" << endl;
    }
};
////////////////////////////////////////////////////////////////////////////////////////
unique_ptr<Ogien[]> straz_pozarna(unique_ptr<Ogien[]> arg, int ilosc)
{
    cout << "Zaczynamy gasic pozar!" << endl;
    arg.reset();
    cout << "Skonczylismy! Zwracamy spalone_drzewo!" << endl;
    return arg;
}
//****************************************************************************************
int main()
{
    unique_ptr<Ogien[]> drzewo {new Ogien[5]};
    unique_ptr zgaszone_drzewo {straz_pozarna(std::move(drzewo), 5)};
}