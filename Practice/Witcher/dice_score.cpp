#include "dice_score.h"
using namespace std;
//************************************************************************************************************************************
Dice_Score::rodzaj_wygranej Dice_Score::jaka_wygrana(rodzaj_kontenera koscie)
{
    vector<int> numery;
    for (const auto &elem : koscie)
    {
        numery.push_back(elem.daj_numer());
    }
    numery = {2, 3, 4, 5, 6};
    sort(numery.begin(), numery.end());

    int wynik = 1;
    for(const auto& elem : numery)
    {
        int powtorzenia = count_if(numery.begin(), numery.end(), [&elem](int liczba)
                               { return elem == liczba; });
        if (powtorzenia > wynik)
            wynik = powtorzenia;
    }

    rodzaj_wygranej jaka = static_cast<rodzaj_wygranej>(wynik);
    if(jaka != rodzaj_wygranej::nic)
        return jaka;

    for (int i = 0; i < ilosc_kosci - 3; ++i)
    {
        bool po_kolei = true;
        int pierwsza_liczba = numery.at(0);
        for (int x = 0; x < numery.size() - 1; ++x)
        {
            if(numery.at(x+1) - numery.at(x) != 1)
            {
                po_kolei = false;
                break;
            }
        }

        if(po_kolei)
        {
            jaka = static_cast<rodzaj_wygranej>(ilosc_kosci + i + pierwsza_liczba);
            break;
        }
    }

    return jaka;
}
//************************************************************************************************************************************
Dice_Score::Dice_Score(int k) : ilosc_kosci(k)
{
    rodzaj_wygranej rodzaj = rodzaj_wygranej::nic;
    int wygrana = 0;
    auto pos = nazwy.begin();

    for(const auto& elem : nazwy)
    {
        nagrody.insert(make_pair(rodzaj, wygrana));
        nazwa_nagrody.insert(make_pair(rodzaj, *pos));

        rodzaj = static_cast<rodzaj_wygranej>(static_cast<int>(rodzaj) + 1);
        ++pos;
        wygrana += 100;
    }
}
//************************************************************************************************************************************
int Dice_Score::daj_wynik(rodzaj_kontenera koscie)
{
    rodzaj_wygranej jaki = jaka_wygrana(koscie);
    auto pos = nagrody.find(jaki);
    return pos->second;
}

//************************************************************************************************************************************
string Dice_Score::daj_nazwe_wyniku(rodzaj_kontenera koscie)
{
    rodzaj_wygranej jaki = jaka_wygrana(koscie);
    auto pos = nazwa_nagrody.find(jaki);
    return pos->second;
}