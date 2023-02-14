// Zadanie 2 - Drzewo binarne z polecenia. Niech uzytkownik wprowadzi najpierw tryb: postfix / prefix. Nastepnie niech wprowadzi okreslone
// symbole az do znaku 'q', wtedy jest koniec wprowadzania. Niech program zgeneruje wizualne drzewo binarne na podstawie wprowadzonych
// przez uzytkownika danych.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class tryb_pracy
{
    postfix = 0,
    prefix
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
tryb_pracy tryb;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<char> operacje = {'+', '-', '*', '/'};
//****************************************************************************************************************
bool czyOperacja(char znak)
{
    if(find(operacje.begin(), operacje.end(), znak) != operacje.end())
    {
        return true;
    } else {
        return false;
    }
}
//****************************************************************************************************************
void wypisz_tryby()
{
    cout << "1 - postfix, 2 - prefix, 3 - exit" << endl;
}
//****************************************************************************************************************
int pobierz_odpowiedz(string napis)
{
    cout << napis;
    int odpowiedz;
    cin >> odpowiedz;
    return odpowiedz;
}
//****************************************************************************************************************
void wybierz_tryb()
{
    wypisz_tryby();

    int odpowiedz = pobierz_odpowiedz("Wybierz tryb: ");

    switch (odpowiedz)
    {
    case 1:
        tryb = tryb_pracy::postfix;
        break;
    case 2:
        tryb = tryb_pracy::prefix;
        break;
    case 3:
        exit(0);
        break;

    default:
        break;
    }
}

//****************************************************************************************************************
vector<char> wprowadz_dane()
{
    vector<char> dane;

    cout << "Wprowadzaj zmienne/operacje rodzialajac ich spacja (np. + 1 2) a zakoncz wprowadzajac 'q': ";
    while(true)
    {
        char znak;
        cin >> znak;

        if(znak == 'q')
            break;
        else
            dane.push_back(znak);
    }

    return dane;
}
//****************************************************************************************************************
void wypisz(vector<char> zbior)
{
    for(const auto& elem : zbior)
    {
        cout << elem;
    }
    cout << endl;
}
//****************************************************************************************************************
void usun_podzespol(vector<char>& smietnik, vector<char>& kopia)
{
    if(smietnik.empty() || kopia.empty())
        return;

    int pozycja1 = 0;
    int pozycja2 = 0;
    bool jest_takie_same = false;

    for (auto pos1 = kopia.begin(), pos2 = smietnik.begin(); pos1 != kopia.end(); ++pos1)
    {
        if(*pos1 == *pos2)
        {
            auto pos1_1 = pos1;
            auto pos2_1 = pos2;

            bool takie_same = true;
            while(pos2_1 != smietnik.end())
            {
                if(*pos1_1 != *pos2_1)
                {
                    takie_same = false;
                    break;
                } else {
                    pos1_1++;
                    pos2_1++;
                }
            }

            if(takie_same) {

                pozycja1 = distance(pos1, kopia.begin());
                pozycja2 = distance(pos1, pos1_1);
                jest_takie_same = true;
                break;
            }
        }
    }

    if(jest_takie_same)
    {
        cout << pozycja1 << ", " << pozycja2 << endl;
        kopia.erase(kopia.begin() + pozycja1, kopia.begin() + (pozycja2));
    }
}

//****************************************************************************************************************
vector<char> analizuj(vector<char> dane)
{
    vector<char> kopia(dane);

    vector<char> wyjscie;

    vector<char> smietnik;

    auto pos = kopia.begin();

    wyjscie.push_back(*pos);
    kopia.erase(pos);


    int ignore = 0;
    bool z_while = false;

    while (!kopia.empty())
    {
        pos = kopia.begin();
        char znak = *pos;

        while (ignore != 0)
        {
            smietnik.push_back(*pos);
            if (czyOperacja(znak))
            {
                ignore += 2;
            }

            pos++;
            znak = *pos;
            ignore--;
            z_while = true;
        }
        

        wyjscie.push_back(*pos);
        kopia.erase(pos);

        if (czyOperacja(znak) && !z_while)
        {
            ignore += 2;
        }
        z_while = false;

        cout << "Smietnik: ";
        wypisz(smietnik);

        usun_podzespol(smietnik, kopia);

        cout << "kopia: ";
        wypisz(kopia);
        //smietnik.clear();
    }

    return wyjscie;
}
//****************************************************************************************************************
int main()
{

        //wybierz_tryb();

        vector<char> dane = {'/', '*', '2', '+', 'a', '3', '+', 'b', '4'}; //= wprowadz_dane();

        wypisz(analizuj(dane));
}