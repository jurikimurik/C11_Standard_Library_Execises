// Zadanie 13 - Przystepcy w pociagu. Masz vector z imonami i nazwiskami osob, ktorzy jada tym pociagiem. Rowniez posiadasz spis przestepcow. Przeszukaj caly pociag i wyrzuc kazdego przestepce z pociagu
// oznajmniajac to wielkim komunikatem.
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//************************************************************************************************************************************************************************************

vector<string> pasazerowie = {"Kajetan Kubiak",
                              "Andrzej Mazur",
                              "Olaf Pawlak",
                              "Boleslaw Szymczak",
                              "Cyprian Krupa",
                              "Ireneusz Pawlak",
                              "Ignacy Jakubowski",
                              "Olaf Sikorska",
                              "Mariusz Brzezinski",
                              "Ireneusz Makowski",
                              "Ignacy Maciejewski",
                              "Amir Lewandowski",
                              "Marcin Wisniewski",
                              "Bartosz Chmielewski",
                              "Heronim Gajewska",
                              "Lukasz Piotrowski",
                              "Mikolaj Czarnecki",
                              "Boleslaw Szczepanski",
                              "Gabriel Malinowski",
                              "Edward Dabrowski"};

vector<string> przestepcy = {"Heronim Gajewska", "Boleslaw Szymczak", "Olaf Sikorska", "Amir Lewandowski"};

//************************************************************************************************************************************************************************************

void wyrzuc(vector<string>& pasazery, vector<string>::iterator pos) {
    cout << "Wyrzucamy z pociagu " << *pos << "! Zegnaj, zlodzieju!" << endl;

    pasazery.erase(pos);
}

bool czyPrzystepca(string osoba) {
    auto pos = find(przestepcy.begin(), przestepcy.end(), osoba);
    if (pos != przestepcy.cend())
    {
        cout << "Przestepca znaleziony!" << endl;
        return true;
    }
    return false;
}

int main()
{
    cout << "Przed przeszukiwaniem: \n";
    for(auto &elem : pasazerowie) {
        cout << "\t" << elem << endl;
    }
    cout << endl;

    auto pos = find_if(pasazerowie.begin(), pasazerowie.end(), czyPrzystepca);
    while (pos != pasazerowie.end())
    {
        wyrzuc(pasazerowie, pos);
        pos = find_if(pasazerowie.begin(), pasazerowie.end(), czyPrzystepca);
    }

    cout << "Po przeszukaniu: \n";
    for (auto &elem : pasazerowie)
    {
        cout << "\t" << elem << endl;
    }
}
