// Zadanie 14. Stworz szablonowa funkjce analizuj(), ktorej wyslesz dwa typy int i int, long i double, char* i string, unsigned int i string
// do analizy na przedmiot:
// - czy sa takie same, - czy jedna jest podstawa drugiej, - czy da sie jeden skonwertowac na drugi
#include <iostream>
#include <type_traits>
using namespace std;
//***********************************************************************************************************************
template<typename T1, typename T2>
void analizuj(string nazwa1, string nazwa2)
{
    cout << nazwa1 << " i " << nazwa2 << ": " << endl;

    if constexpr (is_same<T1, T2>::value)
    {
        cout << "Sa takie same!" << endl; 
    } else {
        cout << "Nie sa takie same!" << endl;
    }

    if constexpr (is_base_of<T1, T2>::value)
    {
        cout << "Klasa " << nazwa1 << " jest podstawa klasy " << nazwa2 << "." << endl;
    } else {
        cout << "Klasa " << nazwa1 << " NIE jest podstawa klasy " << nazwa2 << "!" << endl;
    }

    if constexpr (is_convertible<T1, T2>::value)
    {
        cout << "Klase " << nazwa1 << " da sie skowertowac do klasy " << nazwa2 << "." << endl;
    } else {
        cout << "Klase " << nazwa1 << " NIE da sie skowertowac do klasy " << nazwa2 << "!" << endl;
    }

    cout << endl
         << endl;
}
//***********************************************************************************************************************
int main()
{
    analizuj<int, int>("Int", "Int");

    analizuj<long, double>("Long", "Double");

    analizuj<char *, string>("Char*", "String");

    analizuj<unsigned int, string>("Unsigned int", "String");
}
