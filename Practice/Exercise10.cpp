// Zadanie 10 - Naprawiać tekstu. Masz za zadanie naprawić tekst, który wpisze użytkownik do normalnego stanu.
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string rozdzialacze = {".,?!;:"};
    wstring rozdzialacze_w(rozdzialacze.begin(), rozdzialacze.end());

    string po_jakich_wielka = {".?!;"};
    wstring po_jakich_wielka_w(po_jakich_wielka.begin(), po_jakich_wielka.end());

    wcout << "Wprowadz tekst: ";
    wstring tekst;
    getline(wcin, tekst);

    auto pointer = tekst.begin();
    while (pointer != tekst.end())
    {
        if (find_if(po_jakich_wielka_w.begin(), po_jakich_wielka_w.end(), [&pointer](wchar_t &c)
                    { return (c == *pointer); }) != po_jakich_wielka_w.end())
        {
            cout << "Znalazlem" << endl;
            pointer++;
            if (pointer != tekst.end())
            {
                *pointer = towupper(*pointer);
                continue;
            }
            else
            {
                break;
            }
        }

        *pointer = towlower(*pointer);
        pointer++;
    }

    tekst.erase(remove_if(tekst.begin(), tekst.end(), [](wchar_t &c)
                          { return iswspace(c); }),
                tekst.end());

    auto pos = tekst.find_first_of(rozdzialacze_w);
    while(pos != string::npos)
    {
        
        tekst.insert(pos+1, wstring(1, (wchar_t)' '));

        pos = tekst.find_first_of(rozdzialacze_w, pos + 2);
    }

   

    wcout << tekst << endl;
}