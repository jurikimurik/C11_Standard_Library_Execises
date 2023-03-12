// Zadanie 3 - Kolejka w NFZ. Stworz klase "Chory" z imionem, nazwiskiem i liczba prioritetu. (rowniez zdefiniuj operator>). Stworz kilka
// takich chorych z roznymi prioritetami i niech pan doktor Marek obsluzy kazdego po kolei wedlug prioritetow.
#include <iostream>
#include <queue>
using namespace std;

class Chory
{
private:
    string imie;
    int prioritet;

public:
    Chory(string i, int p) : imie(i), prioritet(p) {}

    string get_imie() const
    {
        return imie;
    }

    int get_prioritet() const
    {
        return prioritet;
    }

    bool operator<(const Chory &inny) const
    {
        return prioritet < inny.get_prioritet();
    }
};

ostream &operator<<(ostream &ekran, const Chory &k)
{
    ekran << k.get_imie();
    return ekran;
}

int main()
{
    Chory Nadia("Babcia Nadia", 1);
    Chory Wlod("Wlodimierz", 1);
    Chory Wisnia("Dawca Krwi Wisnia", 10);
    Chory Olek("Olek ze zlamanym nosem", 13);

    priority_queue<Chory> lista_chorych;
    lista_chorych.push(Wisnia);
    lista_chorych.push(Nadia);
    lista_chorych.push(Wlod);
    lista_chorych.push(Olek);

    while (!lista_chorych.empty())
    {
        cout << "Chory " << lista_chorych.top() << " zostal obsluzony przez kasjerke pana Marek!" << endl;
        lista_chorych.pop();
    }
}