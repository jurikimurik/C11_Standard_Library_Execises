// Zadanie 22 - Książka imion. Posiadasz zbiór imion. Pozwól użytkownikowi posortować jego jako całość lub tylko jako część.
#include "narzedzia.h"
#include "vector"
#include <random>
using namespace std;

vector<string> imiona = {"olek", "jan", "pawel", "patrycja", "klaudia", "elzbieta", "michal", "marek", "jakub", "taras"};

void sortowanie_czesci(vector<string>& cos)
{
    int od = wprowadzenie<int>("Podaj od ktorego mam sortowac:");
    --od;

    int az_do = wprowadzenie<int>("Az do (wlacznie): ");

    if(od > az_do)
    {
        cout << "Zle wprowadzenie" << endl;
        return;
    }

    sort(cos.begin() + od, cos.begin() + az_do);

    
}

int main()
{
    while(true)
    {
        drukuj(imiona, "", "\n");

        cout << "1 - sortuj calosc, 2 - tylko czesc, 3 - rozrzuc, 4 - wyjsc: ";
        int odpowiedz = wprowadzenie<int>();

        switch (odpowiedz)
        {
        case 1:
            sort(imiona.begin(), imiona.end());
            break;
        
        case 2:
            sortowanie_czesci(imiona);
            break;
        
        case 3:
            shuffle(imiona.begin(), imiona.end(), mt19937());
            break;
        
        case 4:
            return 0;

        default:
            break;
        }
        cout << endl;
    }
}