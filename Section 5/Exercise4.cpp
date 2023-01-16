/*4. Stworz kilka roznych tuple ze pomoca konstruktorow domniemanych, zwyklych oraz automatycznych. Nastepnie za pomoca
tie() powiaz zmienne z elementami z jednej z tych krotek i pozmieniaj ich. Sprawdz czy tie() to zmiena w oryginalnym obiekcie
i wpisz odpowiedz: NIE */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <tuple>
using namespace std;
//********************************************************************************************************************************
int main()
{
    tuple<int, u_int32_t, double> t1;
    tuple<string, float, long long> t2{"Hello", 23.9, 12242533523};
    auto t3 = make_tuple("Halloween", 293.535, 'd');

    int l = 10;
    u_int32_t l2 = 23;
    double l3 = 342.34;
    tie(l, l2, l3) = t1;

    /*
        cout << "Przed:";
        cout << get<0>(t1) << endl;
        cout << get<1>(t1) << endl;
        cout << get<2>(t1) << endl;

        get<0>(tuple_ref) = 20;
        get<1>(tuple_ref) = 343;
        get<2>(tuple_ref) = 9494.23;

        cout << "Po:";
        cout << get<0>(t1) << endl;
        cout << get<1>(t1) << endl;
        cout << get<2>(t1) << endl;*/

    // tie(...) przypisuje zmiennym wartosci z krotek
    cout << "l = " << l << ", l2 = " << l2 << ", l3 = " << l3 << endl;
}