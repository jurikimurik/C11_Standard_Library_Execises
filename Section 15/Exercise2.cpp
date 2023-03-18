// Zadanie 2 - Wprowadzając dane. Wpisz za pomocą strumienia dane do int, float, double, string, wstring.
#include <iostream>
using namespace std;

int main()
{
    cout << "Wpisz int: ";
    int liczba_i;
    cin >> liczba_i;

    cout << "Wpisz float: ";
    float liczba_f;
    cin >> liczba_f;

    cout << "Wpisz string: ";
    string napis;
    cin >> napis;

    cout << "Wpisz wstring: ";
    wstring napis_w;
    wcin >> napis_w;

    cout << liczba_i << ", " << liczba_f << ", " << napis << ", ";
    wcout << napis_w << endl;
}