// Zadanie 3 - W powietrze! Ustaw strumien w taki tryb, by wyrzucał wyjątki, jeżeli coś nie będzie mu odpowiadać. Przetestuj to.
#include <iostream>
using namespace std;

int main()
{
    cin.exceptions(ios_base::failbit);

    try {
        cout << "Wprowadz zla liczbe: " << endl;
        int liczba;
        cin >> liczba;

        cout << "Nie zadzialalo :(";
    }
    catch (...)
    {
        cout << "Zadzialalo! Brawo!";
    }
}