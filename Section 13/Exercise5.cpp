// Zadanie 5 - Cenzura. Uzytkownik podaje fraze, ktora nastepnie jest cenzurowana w ten sposob, ze okreslone slowa zostaja zastapione 
// przez inne slowa.

#include "narzedzia.h"
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    string rozd {" ,.;!?"};
   
    map<string, string> cenzura = {make_pair("wolnosc", "ograniczenie"), make_pair("lepszych", "dostosowanych do potrzeb"), make_pair("godnego", "rownego")};

    string fraza = wprowadzenie<string>("Wprowadz fraze: ");

    for(const auto& elem : cenzura) {
       string::iterator pos = search(fraza.begin(), fraza.end(), elem.first.begin(), elem.first.end());

        
     if (pos != elem.first.end())
     {
        string::iterator pos2 = find_first_of(pos, fraza.end(), rozd.begin(), rozd.end());
        fraza.replace(pos, pos2, elem.second);
        
     }

    }

    cout << fraza << endl;
}