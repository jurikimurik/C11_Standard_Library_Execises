/*3. Stworz szablon funkcji drukujancej dowolna ilosc argumentow i sprawdzajaca czy stworzy obiekt 
pair czy tuple i przetestuj to na: (34, 52.5) oraz (&int, uint16_t) */
////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <tuple>
#include <string>
using namespace std;
//**********************************************************************************
template <typename... TArgs>
auto stworz_optymalizacyjne_powiazanie(TArgs ... args)
{
    if constexpr (sizeof...(TArgs) > 2)
    {
        cout << "Masz za duzo typow! Tworzymy tuple!" << endl;
        return tuple<TArgs...>(args...);
    } else if constexpr (sizeof...(TArgs) == 2)
    {
        cout << "Dwa typy, to sie zgadza, tworzymy pair!" << endl;
        return pair<TArgs...>(args...);
    } else {
        cout << "W leb sie piknij, głupcze!" << endl;
        throw std::bad_exception();
    }
}
//**********************************************************************************
int main()
{
    auto super_polaczenie = stworz_optymalizacyjne_powiazanie(34, 52.5);

    int liczba = 2;
    uint16_t niepodpisana_liczba = 234;
    auto duper_polaczenie = stworz_optymalizacyjne_powiazanie(&liczba, niepodpisana_liczba);

    auto muper_puper_polaczenie = stworz_optymalizacyjne_powiazanie(string("Hello, Stary!"), "nie oczekiwales mnie?!", 2993.431);

    //auto proba = stworz_optymalizacyjne_powiazanie("meat");
}