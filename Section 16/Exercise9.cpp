// Zadanie 9 - Kodowanie i zapis UTF-16. Stwórz strumien z kodowaniem utf16, który zapisze tekst podany przez użytkownika do pliku utf16.txt
#include <string>
#include <iostream>
#include <codecvt>
#include <fstream>
using namespace std;

int main()
{


    wofstream uft16outFile("utf16.data");
    uft16outFile.imbue(locale(uft16outFile.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::little_endian>));

    wcout << "Wprowadz polskie nazwisko z dziwnym znaczkiem: ";
    wstring nazwisko;
    wcin >> nazwisko;
    wcout << nazwisko << endl;

    uft16outFile << nazwisko << endl;
}