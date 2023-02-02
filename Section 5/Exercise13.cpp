// Zadanie 13. Stworz szablonowa funkjce analizuj(), ktorej wyslesz na przeanalizowanie typ int, unsigned long, std::string, void*
// na przedmiot: - czy jest calkotiwoliczbowy, - czy jest to typ liczbowy, - czy jest referencja czy obiektem
#include <iostream>
#include <type_traits>
using namespace std;
//***********************************************************************************************************************
template<typename T>
void analizuj(T arg, string nazwa)
{
    cout << nazwa << ":" << endl;

    if constexpr(is_integral<T>::value)
    {
        cout << "Jest calkowitoliczbowy!" << endl;
    } else {
        cout << "Nie jest calkowitoliczbowy!" << endl;
    }

    if constexpr (is_arithmetic<T>::value)
    {
        cout << "Jest typ liczbowy!" << endl;
    }
    else
    {
        cout << "Nie jest typ liczbowy!" << endl;
    }

    if constexpr (is_reference<T>::value)
    {
        cout << "Jest referencją!" << endl;
    }
    else
    {
        cout << "Nie jest referencją!" << endl;
    }

    if constexpr (is_object<T>::value)
    {
        cout << "Jest obiektem!" << endl;
    }
    else
    {
        cout << "Nie jest obiektem!" << endl;
    }
    cout << "\n\n";
}

int probka()
{
    return 2;
}

int main()
{
    analizuj(int(), "Int");

    unsigned long liczba_ul = 2334;
    analizuj(liczba_ul, "Unsigned long");

    analizuj(string(), "String");

}