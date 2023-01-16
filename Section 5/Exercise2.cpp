/*2. Stwórz szablon funkcji tworz_pare, który skorzysta z make_pair oraz wypisze co stworzył.*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <tuple>
#include <typeinfo>
using namespace std;
//*******************************************************************************************************************
template<typename T1, typename T2>
pair<T1, T2> tworz_pare(T1 arg1, T2 arg2)
{
    cout << "Tworzę parę!" << endl;
    cout << "Wartosc pierwszego jest: " << arg1 << endl;
    cout << "Wartosc drugiego jest: " << arg2 << endl;

    return make_pair(arg1, arg2);
}
//*******************************************************************************************************************
int main()
{

    unsigned int liczba = 23;
    const char *tekst = "Jakis napis";

    pair nowa_para {tworz_pare(liczba, tekst)};
}