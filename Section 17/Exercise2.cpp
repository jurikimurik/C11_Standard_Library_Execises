// Zadanie 2 - Wydajność. Potrzebujesz 10.000.000 liczb losowych całkowitoliczbowych od 1 do 10. Porównaj losowość oraz czas 
// na różnych dystrybucjach: Uniform, Bernoulliego, Poissona oraz korzystając dla każdego z nich z trzech różnych mechanizmów losowości.
#include <random>
#include <iostream>
#include <map>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

template <typename Tidst, typename Tre>
void wypiszLosoweLiczby(Tidst dystrybucja, Tre dzwig, const string& nazwa, int ilosc_liczb = 10000000)
{
    auto czas_start = system_clock::now();

    map<long long, int> mapa_wartosci;
    for (int i = 0; i < ilosc_liczb; ++i)
    {
        mapa_wartosci[dystrybucja(dzwig)]++;
    }

    auto dlugosc = duration_cast<milliseconds>(system_clock::now() - czas_start);

    cout << "=========" << endl;
    cout << nazwa << endl;
    cout << "Zajelo to: " << dlugosc.count() << " milisekund. Mapa wynikow: " << endl;
    for (const auto &elem : mapa_wartosci)
    {
        cout << elem.first << ": " << elem.second << endl;
    }
    cout << "=========" << endl
         << endl
         << endl;
}


int main()
{
    knuth_b kE;
    mt19937 mtE;
    ranlux24 rlxE;

    uniform_int_distribution ud(1, 10);
    binomial_distribution bd(10);
    poisson_distribution pd;

    string nazwa = "unform_int_distribution - ";
    wypiszLosoweLiczby(ud, kE, nazwa + "knuth_b");
    wypiszLosoweLiczby(ud, mtE, nazwa + "mt19937");
    wypiszLosoweLiczby(ud, rlxE, nazwa + "ranlux24");

    nazwa = "binormal_distribution - ";
    wypiszLosoweLiczby(bd, kE, nazwa + "knuth_b");
    wypiszLosoweLiczby(bd, mtE, nazwa + "mt19937");
    wypiszLosoweLiczby(bd, rlxE, nazwa + "ranlux24");

    nazwa = "poisson_distribution - ";
    wypiszLosoweLiczby(pd, kE, nazwa + "knuth_b");
    wypiszLosoweLiczby(pd, mtE, nazwa + "mt19937");
    wypiszLosoweLiczby(pd, rlxE, nazwa + "ranlux24");
}