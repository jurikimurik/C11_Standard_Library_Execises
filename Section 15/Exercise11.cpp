// Zadanie 11 - Zamiana słów. Niech strumien zostanie ustawiony na pozycje odczytu na samym początku i przeczyta cala linijkę. 
//(pliku linijka.lin). Następnie użytkownik wprowadzi swoje zdanie, które musi być zastapione zamiast poprzedniego zdania w całości.
#include <iostream>
#include <fstream>
#include "../narzedzia.h"
using namespace std;

int main()
{
    fstream plik("linijka.lin", ios::in);

    cout << "Linijka tekstu: " << plik.rdbuf() << endl;
    plik.close();

    string linijka = wprowadzenie<string>("Wprowadz wlasna linijke: ");
    plik.open("linijka.lin", ios::out | ios::trunc);
    plik << linijka;
    plik.close();

    plik.open("linijka.lin", ios::in);
    cout << "Zmieniona linijka: " << plik.rdbuf();
}