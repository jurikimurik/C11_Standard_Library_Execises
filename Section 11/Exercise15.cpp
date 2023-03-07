// Zadanie 15 - Copy Vs. Move. Posiadasz 100 000 liczb losowych w wektorze. Porównaj szybkość kopiowania za pomocą metody copy oraz move.
#include <vector>
#include <chrono>
#include <iostream>
using namespace std;
//******************************************************************************************************************************
class SuperInteger
{
    int liczba;

    int *ilosc_liczb;

public:
    SuperInteger(int l) : liczba(l) { ilosc_liczb = new int[liczba]; }

    ~SuperInteger() { delete ilosc_liczb; }

    SuperInteger(const SuperInteger& inny)
    {
        liczba = inny.liczba;
        ilosc_liczb = new int[liczba];
    }

    SuperInteger(SuperInteger &&do_utylizacji) {
        if(do_utylizacji == *this)
            return;

        ilosc_liczb = do_utylizacji.ilosc_liczb;
        liczba = do_utylizacji.liczba;

        do_utylizacji.ilosc_liczb = nullptr;
    }

    bool operator==(const SuperInteger& inny) const
    {
        return liczba == inny.liczba && ilosc_liczb == inny.ilosc_liczb;
    }

    
};
//******************************************************************************************************************************
void wypelnij_wektor(vector<SuperInteger>& liczby, int ilosc_liczb = 500000)
{
    srand(time(NULL));

    liczby.reserve(ilosc_liczb);

    while(ilosc_liczb > 0)
    {
        liczby.push_back(rand() % ilosc_liczb);
        ilosc_liczb--;
    }
}
//******************************************************************************************************************************
int main()
{
    vector<SuperInteger> liczby;
    wypelnij_wektor(liczby);

    vector<SuperInteger> pierwszy;
    auto czas = chrono::system_clock::now();
    copy(liczby.begin(), liczby.end(), back_inserter(pierwszy));
    cout << "Czas potrzebny (copy): " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << " ms." << endl;

    vector<SuperInteger> drugi;
    czas = chrono::system_clock::now();
    move(liczby.begin(), liczby.end(), back_inserter(drugi));
    cout << "Czas potrzebny (move): " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << " ms." << endl;
}