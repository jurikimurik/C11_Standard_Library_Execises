// Zadanie 18 - Bez pierwszych! Wypełnij kolejkę deque liczbami kolejnymi zaczynajac od 10 i do 100. Następnie zmień każdą pierwsza 
// liczbę na 0 i wypisz tą kolejkę.
#include <deque>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;
//********************************************************************************************************************************
int main()
{
    deque<int> kolejka;
    kolejka.resize(100 - 10 + 1);
    iota(kolejka.begin(), kolejka.end(), 10);

    transform(kolejka.begin(), kolejka.end(), ostream_iterator<int>(cout, " "), [](int &liczba)
                { 
            for (int i = 2; i < liczba; ++i) {
                if(liczba % i == 0)
                    return liczba;
            }

            return 0; 
            });
}