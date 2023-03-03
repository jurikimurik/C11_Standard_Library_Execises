#include "screen.h"
using namespace std;
//************************************************************************************************************
void Screen::zaladuj_obiekty()
{
    oczyszcz(true);
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
void Screen::odswiez(bool czy_ladowac_obiekty)
{
    system("clear");

    if(czy_ladowac_obiekty)
    zaladuj_obiekty();

    for(const auto& elem: dane)
    {
        cout << elem;
        if(elem.back() != '\0')
            cout << endl;
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
void Screen::wprowadzenie(bool czy_wlaczyc, const Text_Object &obj)
{
    if(czy_wlaczyc == false) {
        oczyszcz(true);
    }

    odswiez();

    resolution_t wymiary_ekranu = get_resolution();
    coordinates_t koordynaty = obj.get_coordinates();

    string visual = obj.daj_wizualna_reprezentacje();
    string znak_konca = "\n";

    int dystans = 0;

    int ilosc_wierszy = count(visual.begin(), visual.end(), '\n') + 1;
    if (ilosc_wierszy == 1)
    {
        dystans = visual.length();
    }
    else
    {
        dystans = distance(find_end(visual.begin(), visual.end(), znak_konca.begin(), znak_konca.end()), visual.end()) - 1;
    }

    int x_end = koordynaty.first + dystans;
    int y_end = koordynaty.second + ilosc_wierszy - 1;


    for (int y = y_end; y != wymiary_ekranu.second; ++y)
    {
        for (int x = x_end; x != wymiary_ekranu.first; ++x)
        {
            dane[y][x] = '\0';
        }
        x_end = 0;
    }

    odswiez(false);
}