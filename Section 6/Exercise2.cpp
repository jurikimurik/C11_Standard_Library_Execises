// Zadanie 2. Stworz kontener typu map o nazwie pulaNagrody, ktory zainicjalizujesz wartosciami poczatkowymi {1, "zloto"},{2, "diament"},{3, "nic"},{4, "jaszczur"},{5, "mapa skarbow"}. Nastpenie stworz
// kontener list o nazwie klucze, z zainicjalizowanymi wartosciami {1,3,5,3,4,3,1}. Niech po kolei dla kazdego z obiektow konteneru klucze zostanie sprawdzona odpowiednia my wartosc z pulaNagrody i bedzie
// wypisana na ekranie z tekstem "co znalazles: "
#include <map>
#include <list>
#include <iostream>
using namespace std;
//****************************************************************************************************************************************************************************************
int main()
{
    map<int, string> pulaNagrody = {{1, "zloto"},
                                    {2, "diament"},
                                    {3, "nic"},
                                    {4, "jaszczur"},
                                    {5, "mapa skarbow"}};

    list klucze = {1, 3, 5, 3, 4, 3, 1};
    while(!klucze.empty())
    {
        cout << "Co znalazles: " << pulaNagrody[klucze.front()] << endl;
        klucze.pop_front();
    }
}