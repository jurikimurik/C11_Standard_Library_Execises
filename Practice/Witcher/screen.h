#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <utility>
#include <vector>
#include "text_object.h"
#include <algorithm>
///////////////////////////////////////////////////////////////
enum class position
{
    lewa_gora = 0,
    srodek_gora,
    prawa_gora,
    lewa_srodek,
    srodek,
    prawa_srodek,
    lewa_dol,
    srodek_dol,
    prawy_dol
};
///////////////////////////////////////////////////////////////
using resolution_t = std::pair<int, int>;
using coordinates_t = std::pair<int, int>;
///////////////////////////////////////////////////////////////
class Screen
{
    private :
        resolution_t resolution;
        std::vector<std::string> dane;
        std::vector<const Text_Object *> objekty;

        void zaladuj_obiekty();

        public :
            Screen(int x = 30, int y = 10) : resolution(std::make_pair(x, y)), dane(y, std::string(x, 'S')){}

        void odswiez();

        Screen & operator+(const Text_Object &obj);

        Screen & operator-(const Text_Object &obj);

        void oczyszcz(bool tylko_dane = false){
            dane.clear();
            std::string pusty(resolution.first, 'S');
            for (int i = 0; i < resolution.second; ++i){
                dane.push_back(pusty);}

                if (!tylko_dane)
                objekty.clear();
            
            }

        resolution_t get_resolution() const
        {
                return resolution;
        }

        coordinates_t get_coordinate_position(position pozycja);

        void tryb_wprowadzania(bool czy_wlaczyc, const Text_Object &obj = Text_Object());
};

#endif