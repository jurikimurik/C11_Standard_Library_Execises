// Zadanie 8 - Kodowanie i zapis UTF-8. Użytkownik podaje tekst w postaci wstringu. Następnie ten tekst należy przekonwertować na UTF-8 i 
// zapisać do pliku utf8.
#include <codecvt>
#include <locale>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// konwertuj lancuch UTF-8 na lancuch wstring
std::wstring utf8_to_wstring(const std::string& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.from_bytes(str);
}

// konwertuj lancuch wstring na lancuch UTF-8
std::string wstring_to_utf8 (const std::wstring& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.to_bytes(str);
}

int main()
{
    wcout << "Wprowadz polskie nazwisko ze specyficzna litera: ";
    wstring nazwisko;
    wcin >> nazwisko;

    string nazwisko_utf8 = wstring_to_utf8(nazwisko);

    ofstream utf8out("utf8.data");
    utf8out << nazwisko_utf8 << endl;
}