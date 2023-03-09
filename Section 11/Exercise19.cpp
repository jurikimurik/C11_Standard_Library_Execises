// Zadanie 19 - Program generuje użytkownikowi hasło i wypisuje go. Następnie użytkownik może z niego usunąć określoną literę lub od 
// określona jego część. Również może zrobić tak, żeby elementy sąsiadujące ze sobą się nie powtarzały.
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
//************************************************************************************************************
string generuj_haslo()
{
    srand(time(NULL));

    int dlugosc = 12;
    string haslo;
    for (int i = 0; i < dlugosc; ++i)
    {
        haslo.push_back(static_cast<char>(rand() % 4 + 33));
    }

    return haslo;
}
//************************************************************************************************************
void usun_litere(string& haslo)
{
    cout << "Podaj litere: ";
    char znak;
    cin >> znak;

    haslo.erase(remove(haslo.begin(), haslo.end(), znak), haslo.end());
}
//************************************************************************************************************
void usun_czesc(string &haslo)
{
    cout << "Od indeksu wlacznie: ";
    int od;
    cin >> od;

    cout << "Do indeksu wlacznie: ";
    int az_do;
    cin >> az_do;
    az_do--;

    string::iterator pos1 = haslo.begin() + od;
    string::iterator pos2 = haslo.begin() + az_do;

    haslo.erase(od, az_do);
}
//************************************************************************************************************
int main()
{
    string haslo = generuj_haslo();

    while(true)
    {
        cout << "Haslo: " << haslo << endl;

        cout << "1 - usun wszystkie okreslone litery, 2 - usun czesc hasla, 3 - zeby sasiadujace sie nie powtarzaly, 4 - wyjscie: ";
        int odpowiedz;
        cin >> odpowiedz;

        switch (odpowiedz)
        {
        case 1:
            usun_litere(haslo);
            break;
        case 2:
            usun_czesc(haslo);
            break;
        case 3:
            haslo.erase(unique(haslo.begin(), haslo.end()), haslo.end());
            break;
        case 4:
            return 0;

        default:
            break;
        }
        cout << endl;
    }
}