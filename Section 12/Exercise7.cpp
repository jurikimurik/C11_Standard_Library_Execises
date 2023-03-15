// Zadanie 7 - Generator hasel. Uzytkownik podaje fraze, ktora nastepnie program musi przerobic na silne haslo i pokaza uzytkownikowi.
#include "narzedzia.h"
#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));

    string fraza = wprowadzenie<string>("Podaj fraze: ");

    cout << "Przerabiamy ja na haslo!" << endl;
    
    string rozdzielacze{"\\\t\n ,;.!?<>"};
    string znaki_specjalne{"!?><"};

    auto pos = find_first_of(fraza.begin(), fraza.end(), rozdzielacze.begin(), rozdzielacze.end());
    // Oczyszczamy
    while(pos != fraza.end())
    {
        fraza.erase(pos);

        pos = find_first_of(fraza.begin(), fraza.end(), rozdzielacze.begin(), rozdzielacze.end());
    }

    // Zmienjszamy
    for_each(fraza.begin(), fraza.end(), [] (char&c) {
        c = tolower(c);
    });

    // Dajemy znaki dookola
    char* znak_specjalny = &znaki_specjalne[rand() % znaki_specjalne.size()];

    fraza.insert(0, 1, *znak_specjalny);
    fraza.insert(fraza.size(), 1, *znak_specjalny);

    // Powiekszenie
    fraza.at(1) = toupper(fraza.at(1));

    // Cyferki
    for(int i = 0; i < rand() % 5; ++i)
    {
        fraza.insert(fraza.size()-1, 1, 1+48 + rand() % 10);
    }

    cout << "Gotowe haslo: " << fraza << endl;
}