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
                if(*wsk != ' ')
                {
                    dane[y][x] = *wsk;
                }
                
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
//************************************************************************************************************
coordinates_t Screen::get_coordinate_position(position pozycja)
{
    resolution_t wymiary = get_resolution();
    coordinates_t koordynaty = make_pair(0, 0);

    switch (pozycja)
    {
    case position::lewa_gora:
        koordynaty = make_pair(0, 0);
        break;
    case position::srodek_gora:
        koordynaty = make_pair(wymiary.first / 2, 0);
        break;
    case position::prawa_gora:
        koordynaty = make_pair(wymiary.first, 0);
        break;

    case position::lewa_srodek:
        koordynaty = make_pair(0, wymiary.second / 2);
        break;
    case position::srodek:
        koordynaty = make_pair(wymiary.first / 2, wymiary.second / 2);
        break;
    case position::prawa_srodek:
        koordynaty = make_pair(wymiary.first, wymiary.second / 2);
        break;

    case position::lewa_dol:
        koordynaty = make_pair(0, wymiary.second);
        break;
    case position::srodek_dol:
        koordynaty = make_pair(wymiary.first / 2, wymiary.second);
        break;
    case position::prawy_dol:
        koordynaty = make_pair(wymiary.first, wymiary.second);
        break;

    default:
        break;
        }

    return koordynaty;
}
//************************************************************************************************************
void tryb_wprowadzania(bool czy_wlaczyc, const Text_Object &obj = Text_Object())
{
    
}