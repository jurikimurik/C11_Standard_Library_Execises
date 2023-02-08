// Zadanie 7 - Sprawdzenie wydajnosci. Stworz vector<int> i list z liczbami od 0 do 200000. Nastepnie do kazdej z tych kontenerow na poczatek dodaj liczby od 2001 do 4000. Oblicz z jaka szybkoscia robi to 
//vector i z jaka list. Porownaj te dwa wyniki.
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;
//********************************************************************************************************************************************************************************
int main()
{
    vector<int> wektor;
    list<int> lista;

    int liczba = 200000;
    for (int i = 0; i < liczba; ++i) {
        wektor.push_back(i);
        lista.push_back(i);
    }

    auto czas = chrono::system_clock::now();

   
    for (int i = 0; i < liczba; ++i)
    {
        wektor.insert(wektor.begin(), i);
    }
    cout << "Dla wektora: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << endl;

    czas = chrono::system_clock::now();
    for (int i = 0; i < liczba; ++i)
    {
        lista.insert(lista.begin(), i);
    }
    cout << "Dla listy: " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << endl;
}