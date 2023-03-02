// Zadanie 14 - Ciagly ciag. Uzytkownik podaje okreslony ciag. Program stwierdza czy jest posortowany. Jezeli nie, to pokazuje miejsce od
// ktorego nie sa posortowane. Nastepnie probuje stwierdzic czy nie jest podzielony na parzyste i nieparzyste. Jezeli sie nie uda, to 
// sprawdza na koniec czy nie jest to po prostu stog.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//*********************************************************************************************************************
bool czyParzyste(int liczba)
{
    return liczba % 2 == 0;
}
//*********************************************************************************************************************
vector<int> pobierz_ciag()
{

    cout << "Wprowadz liczby rozdzialajac ich spacjami lub ENTERem a na koncu wprowadz znak q: ";
    vector<int> ciag;
    while(cin)
    {
        int liczba;
        cin >> liczba;
        ciag.push_back(liczba);
    }
    ciag.pop_back();
    cin.clear();
    cin.ignore();

    return ciag;
}
//*********************************************************************************************************************
int main()
{
    vector<int> ciag = pobierz_ciag();

    if(is_sorted(ciag.begin(), ciag.end()))
    {
        cout << "Ciag jest posortowany" << endl;
    }
    else
    {
        auto pos = is_sorted_until(ciag.begin(), ciag.end());
        cout << "Ciag nie jest posortowany od pozycji: " << distance(ciag.begin(), pos) + 1 << "." << endl;
    }

    if(is_partitioned(ciag.begin(), ciag.end(), czyParzyste))
    {
        cout << "Ciag jest podzielony na parzyste i nieparzyste. " << endl;
    } else {
        cout << "Ciag NIE jest podzielony na parzyste i nieparzyste. " << endl;
        cout << "Sprawdzam czy nie stog..." << endl;
        if(is_heap(ciag.begin(), ciag.end()))
        {
            cout << "Tak! To jest stog!" << endl;
        } else {
            cout << "To nawet stogiem nie jest. Zbiorowisko smieci!" << endl;
        }
    }
}