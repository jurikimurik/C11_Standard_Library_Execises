// Zadanie 1 - Sprawdzacz klientów. Masz podany ciąg string w postaci XML z danymi osoby w pizzerii. Sprawdź czy posiada pole 
// o nazwie: „zamówienia”.
#include <regex>
#include <iostream>
using namespace std;

int main()
{
     string Lolek{"<osoba><imie>Lolek</imie><zamowienia>1</zamowienia></osoba>"};
     string Maks{"<osoba><imie>Maks</imie></osoba>"};

     regex reg("<(zamowienia)>.*</(\\1)>");
     bool found1 = regex_search(Lolek, reg);
     bool found2 = regex_search(Maks, reg);

     cout << boolalpha << "Czy znaleziono u Lolka: " << found1 << endl;
     cout << boolalpha << "Czy znaleziono u Maksa: " << found2 << endl;
}