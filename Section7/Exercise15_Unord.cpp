// Zadanie 15 - Worek v.2. Masz poczatkowy kontener unordered_set z losowymi 5-ma liczbami. W kolko pytaj sie uzytkownika czy chce dodac nowe elementy/sprawdzic czy jest tam okreslony/usunac jakis element.
// Niech program sie skonczy wpisaniem litery 'q'.
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
//************************************************************************************************************************************************************************
char pobierz_dzialanie()
{
    char dzialanie;
    cin >> ws >> dzialanie;
    return dzialanie;
}

//************************************************************************************************************************************************************************
void wypisz_set(unordered_set<int> zbior)
{
    for(const auto& elem : zbior) {
        cout << elem << ", ";
    }
    cout << endl;
}

//************************************************************************************************************************************************************************
int main()
{
    unordered_set<int> liczby;

    srand(time(NULL));
    for (int i = 0; i < 5; ++i) 
    {
        liczby.insert(rand() % 5);
    }

   

while (true)
{
        wypisz_set(liczby);
        cout << "Co chcesz zrobic? (1 - nowe elementy, 2 - sprawdzic, 3 - usunac, q - wyjsc): ";
        int liczba = 0;
        char dzialanie = pobierz_dzialanie();
        switch (dzialanie)
        {
        case '1':
            cout << "Wprowadzaj liczby, a gdy skonczysz wprowadz znak 'e': ";

            while(true) {
                cin >> liczba;
                if(cin)
                    liczby.insert(liczba);
                else
                    break;
            }
            cin.clear();
            cin.ignore();

            break;
        case '2':
            cout << "Wpisz liczbe do sprawdzenia: ";
        
            cin >> liczba;

            if(liczby.find(liczba) != liczby.end())
                cout << "Liczba istnieje w zbiorze!" << endl;
            else
                cout << "Liczby w zbiorze NIE ma!" << endl;
            break;
        case '3':
            cout << "Wpisza jaka liczbe chcesz usunac: ";
            cin >> liczba;

            liczby.erase(liczba);
            cout << "Jezeli byli w zbiorze, zostaly usuniete!" << endl;
            break;
        case 'q':
            return 0;
            break;

        default:
            cout << "SKACZE";
            break;
        }
}

    
}