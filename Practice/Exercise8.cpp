// Zadanie 8 - Binarne działania. Zapisz jakiś tekst binarnie do pliku a następnie go odczytaj.
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
    wcout << "Wprowadz tekst nawet po polsku: ";
    wstring tekst;
    getline(wcin, tekst);

    wofstream strm("tekst.txt", ios_base::binary);
    strm.write(&tekst[0], sizeof(tekst));
    strm.close();

    wifstream strm_r("tekst.txt", ios_base::binary);
    wstring tekst_z_pliku;
    
    while(strm_r)
    {
        wchar_t wznak;
        strm_r.get(wznak);
        if(strm_r)
            tekst_z_pliku.push_back(wznak);
    }
    strm_r.close();

    wcout << tekst_z_pliku << endl;
}