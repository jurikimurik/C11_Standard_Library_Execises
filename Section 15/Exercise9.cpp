// Zadanie 9 - Obliczenia. Niech program obliczy jakieś skomplikowane wyrażenie matematycznie i zapisze wynik swojego działania do 
// pliku tymczasowego „obliczenia.tmp”. Następnie program poprosi użytkownika o podanie własnej liczby, która chce dodać do obliczeń. 
// Po czym program wyświetli liczbę z pliku i doda do niej wartość użytkownika.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream("obliczenia.tmp") << (1.423 / 2.323 * 429.234 / 23 + 238493 - 1234 * 23 + 2.34) / 2.3;

    cout << "Dawaj liczbe: ";
    int liczba;
    cin >> liczba;

    double liczba_w_tmp;
    ifstream("obliczenia.tmp") >> liczba_w_tmp;

    cout
        << ifstream("obliczenia.tmp").rdbuf() << " + " << liczba << " = " << liczba_w_tmp + liczba << endl;
}