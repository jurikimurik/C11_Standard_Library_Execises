// Zadanie 7 - Niech żyje angielski! Masz podany plik z nazwiskami osób po polsku z polskimi literami. (nazwiska.data) Niech program 
// wczyta te wszystkie nazwiska i przekonwertuje ich na zwyczajny string. Następnie niech wypisze te nazwiska na ekranie.

#include <locale>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


// kowertuj string na wstring
std::wstring to_wstring(const string& str, const std::locale& loc = std::locale())
{
    std::vector<wchar_t> buf(str.size());
    std::use_facet<std::ctype<wchar_t>>(loc).widen(str.data(), str.data() + str.size(), buf.data());
    return std::wstring(buf.data(), buf.size());
}

// konwertuj wstring na string z domyslnym znakiem '?' dla znakow spoza zestawu
std::string to_string(const std::wstring& str, const std::locale& loc = std::locale())
{
    std::vector<char> buf(str.size());
    std::use_facet<std::ctype<wchar_t>>(loc).narrow(str.data(), str.data() + str.size(), '?', buf.data());
    return std::string(buf.data(), buf.size());
}

int main()
{
    wifstream strm("nazwiska.data");
    string nazwiska;

    while(strm)
    {
        wstring nazwisko;
        strm >> nazwisko;
        if(strm)
            nazwiska += to_string(nazwisko) + "\n";
    }

    cout << nazwiska;
}