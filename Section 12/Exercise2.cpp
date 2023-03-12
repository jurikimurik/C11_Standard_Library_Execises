// Zadanie 2 - Kolejka w Biedronce. Stworz klase "Klient" z imionem i nazwiskiem. Stworz kilka takich klientow i umieszcz ich w kolejce do
// kasy. Nastepnie niech pani Kasia obsluzy ich wszystkich po kolei i wypisze na ekranie.
#include <iostream>
#include <queue>
using namespace std;

class Klient
{
private:
    string imie;

public:
    Klient(string i) : imie(i) {}

    string get_imie() const
    {
        return imie;
    }
};

ostream &operator<<(ostream &ekran, const Klient &k)
{
    ekran << k.get_imie();
    return ekran;
}

int main()
{
    Klient Stachu("Staszek");
    Klient Maks("Maks");
    Klient Evgeniy("Evgeniy");

    queue<Klient> kasa;
    kasa.push(Maks);
    kasa.push(Stachu);
    kasa.push(Evgeniy);

    while (!kasa.empty())
    {
        cout << "Klient " << kasa.front() << " zostal obsluzony przez kasjerke pania Kasie!" << endl;
        kasa.pop();
    }
}