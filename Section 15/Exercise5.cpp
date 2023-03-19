// Zadanie 5 - Polskie znaczki tez się liczą! Za pomocą podstawowych funkcji pobierających, pobierz tekst z polskimi znaczkami a 
// następnie wypisz go na ekranie.
#include <iostream>
using namespace std;

int main()
{
    wchar_t znaczek;
    wstring poslkie_slowo;

    while(wcin.get(znaczek))
    {
        poslkie_slowo += znaczek;
    }

    wcout << "Twoje slowo: " << poslkie_slowo << endl;
}