// Zadanie 23 - Uszkodzona sortownica. Posiadasz zbiór liczb. Niech użytkownik wbierze według której liczby ma być posortowana ta tablica. 
// Następnie wypisz te liczby.
#include "narzedzia.h"
#include <deque>

deque<int> liczby = {13, 24, 52, 64, 54, 33, 24, 34};

int main()
{
    drukuj(liczby, "", "\n");

    int odpowiedz = wprowadzenie<int>("Wedlug ktorej ma byc posortowana ta tablica: ");

    nth_element(liczby.begin(), find(liczby.begin(), liczby.end(), odpowiedz), liczby.end());

    drukuj(liczby);
}