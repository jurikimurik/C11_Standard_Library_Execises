/*1. Stwórz kilka różnych par typu Klucz (int) i Zamek (string). Wykorzystaj 
konstruktory domniemane, zwykle oraz automatyczne. Następnie stwórz referencje
do jednego z tych kluczy i zamku w osobnej parze. Za pomocą referencji zmień 
wartość prawdziwą i sprawdź ją.*/
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <tuple>
using namespace std;
//*****************************************************************************
int main()
{
    pair<int, string> para_pierwsza;

    int klucz_skrabeusz = 10;
    string zamek_skarabeusz = "ZAMEK";
    auto para_druga = make_pair(klucz_skrabeusz, zamek_skarabeusz);

    using klucz_t = int;
    using zamek_t = string;

    pair<klucz_t, zamek_t> para_trzecia{34, "ZAMEK DO 34"};

    using ref_t_pierwszy = decltype(para_pierwsza.first) &;
    using ref_t_drugi = decltype(para_pierwsza.second) &;

    pair<ref_t_pierwszy, ref_t_drugi> para_pierwsza_ref{ref(para_pierwsza.first), ref(para_pierwsza.second)};

    cout << "PRZED: " << para_pierwsza.first << endl;
    para_pierwsza_ref.first = 22;
    cout << "PO: " << para_pierwsza.first << endl;
}