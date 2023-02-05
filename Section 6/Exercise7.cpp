// Zadanie 7 - Sortujacy terminal. Niech uztykownik wprowadzi dowolną sekwencje liczb. Nastepnie, po wprowadzeniu niech wpisze jakikolwiek znak, oznaczajacy wyjscie z trybu wprowadzenia.
// Twoim zadaniem jest wypisac ten ciag na ekranie i sie spytac z jakiego elementu po jaki element ciag dany musi byc posortowany. Wypisz ten ciag a pod koniec wypisz go w kolejnosci odwrotnej.
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    deque<int64_t> sekwencja;
    while(true) {
        cout << "Wprowadz liczbe do konteneru: ";
        int64_t liczba;
        cin >> liczba;
        if(!cin)
            break;
        sekwencja.push_back(liczba);
    }
    cin.clear();
    cin.ignore();

    cout << endl
         << endl
         << "Ciag danych: ";
    for (const auto &elem : sekwencja)
    {
        cout << elem << ' ';
    }
    cout << endl;

    cout << "Od jakiego po jaki element mam posortowac? Wpisz dwie liczby. " << endl;
    int from;
    cin >> from;
    from--;
    if(from < 0)
        from = 0;
    
    int to;
    cin >> to;
    to++;
    if (to > sekwencja.size())
        to = sekwencja.size();

    sort(sekwencja.begin() + from, sekwencja.begin()+to);

    for(const auto& elem : sekwencja)
    {
        cout << elem << ' ';
    }
    cout << endl;

    reverse(sekwencja.begin(), sekwencja.end());

    for(const auto& elem : sekwencja)
    {
        cout << elem << ' ';
    }
    cout << endl;
}