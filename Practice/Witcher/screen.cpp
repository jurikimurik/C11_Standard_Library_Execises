#include "screen.h"
using namespace std;
//************************************************************************************************************
void Screen::zaladuj_obiekty()
{
    oczyszcz(true);

    cout << "TYLE MAM OBJEKTOW: " << objekty.size() << endl;
    for (const auto &elem : objekty)
    {
        string reprezentacja = elem->daj_wizualna_reprezentacje();
        pair<int, int> coordinates = elem->get_coordinates();
        auto wsk = reprezentacja.begin();

        for (int y = coordinates.second; wsk != reprezentacja.end(); ++y)
        {
            for (int x = coordinates.first; *wsk != '\n' && wsk != reprezentacja.end(); ++x, ++wsk)
            {
                dane[y][x] = *wsk;
            }
            if(*wsk == '\n')
                ++wsk;
        }
    }
}
//************************************************************************************************************
void Screen::odswiez()
{
    system("clear");

    zaladuj_obiekty();

    for(const auto& elem: dane)
    {
        cout << elem << endl;
    }
}
//************************************************************************************************************
Screen &Screen::operator+(const Text_Object &obj)
{
    objekty.push_back(&obj);
    return *this;
}
//************************************************************************************************************
Screen &Screen::operator-(const Text_Object &obj)
{
    objekty.erase(remove(objekty.begin(), objekty.end(), &obj), objekty.end());
    return *this;
}