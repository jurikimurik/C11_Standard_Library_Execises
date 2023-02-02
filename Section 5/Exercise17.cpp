// Zadanie 17. Stworz klase A, w niej niech bedzie swoja dynamiczna tablica obiektow typu elementy o typie int.
// Stworz nastepnie funkcje swap, ktora zamienia tablice elems z jednego obiektu do drugiego i odwrotnie 
// (realizuj swap dla dwoch pojedynczych obiektow klasy A)
// Przetestuj stworzona funkcje na podstawie dwoch ciagow: [2, 5, 3, 4] i [-2, 64, 37, 12].
#include <iostream>
#include <utility>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class A {
    int *elementy;
    int ilosc_elementow;

public:

    A(initializer_list<int> lista)
    {
        ilosc_elementow = lista.size();
        elementy = new int[ilosc_elementow];
        for (int i = 0; int elem : lista)
        {
            elementy[i++] = elem;
        }
    }

    void wypisz()
    {
        for (int i = 0; i < ilosc_elementow; i++)
        {
            cout << i << ": " << elementy[i] << endl;
        }
    }

    void swap(A &inny_obiekt)
    {
        std::swap(elementy, inny_obiekt.elementy);
        std::swap(ilosc_elementow, inny_obiekt.ilosc_elementow);
    }
};
//************************************************************************************************************************
int main()
{
    cout << "PRZED SWAP: " << endl;

    A super_klasa = {2, 5, 3, 4};
    super_klasa.wypisz();

    A super_inna_klasa = {-2, 64, 37, 12};
    super_inna_klasa.wypisz();

    super_klasa.swap(super_inna_klasa);

    cout << "PO SWAP: " << endl;

    
    super_klasa.wypisz();
    super_inna_klasa.wypisz();
}