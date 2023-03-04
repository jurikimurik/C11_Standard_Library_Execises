#include "text_object.h"
using namespace std;
//****************************************************************************************************************************
int Text_Object::daj_szerokosc(int ktory_y)
{
        auto text = daj_wizualna_reprezentacje();

        if(ktory_y == -1)
        {
            vector<int> szerokosci;

            auto pos = text.begin();
            do
            {
                szerokosci.push_back(distance(pos, find(pos+1, text.end(), '\n')));
                pos = find(pos+1, text.end(), '\n');
                if(pos != text.end())
                    pos++;

            } while (pos != text.end());

            return *max_element(szerokosci.begin(), szerokosci.end());
            
        } else {
            
            --ktory_y;
            auto pos_od = find_if(text.begin(), text.end(), [&ktory_y] (char c) {
                if(c == '\n')
                {
                    --ktory_y;
                }

                return ktory_y == 0;
            });
            if(pos_od != text.begin())
                pos_od++;

            string znak = "\n";
            auto pos_do = find(next(pos_od), text.end(), '\n');

            int szerokosc = distance(pos_od, pos_do);

            return szerokosc;
        }
    }