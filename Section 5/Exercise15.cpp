// Zadanie 15. Stworz szablonowa funkjce modufikuj(), ktorej wyslesz jeden typ do modyfikacji na przedmiot:
// - dodanie const i volatile
#include <iostream>
#include <type_traits>
using namespace std;
//************************************************************************************************************
template <typename T>
decltype(auto) modyfikuj(T arg)
{
    using new_T = typename add_cv<T>::type;
    new_T liczba = arg;
    return liczba;
}
//************************************************************************************************************
int main()
{
    int liczba = 1232;
    auto nowa_liczba = modyfikuj(liczba);

    nowa_liczba++;
    cout << nowa_liczba;
}