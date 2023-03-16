// Zadanie 3 - Detektyw. Posiadasz długi ciąg string z tekstem wśród którego jest zakodowane przesłanie. Przesłanie jest złożone z 
// pojedynczych słów, które występują po interpunkcji. Za pomocą iteratorów regex wypisz przesłanie, które ukrył poszukiwany.
#include <regex>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string dane = {"Wielki dzien zaczyna sie z wielkiego ja. Spotkanie naprawde bylo przyjemne a caly dzien ja poswiecilem swojej nauce. Tam pilnie pracowalem"
    "oraz kwiatki ogladalem. Gdzie tak slonce sie spieszy? Zawsze w zlym czasie a wiec bywaj!"};

    regex reg("[.?!] ([A-Za-z]+)");
    smatch m; // do zwracanych szczegolow dopasowania
    bool found = regex_search(dane, m, reg);

    sregex_iterator beg(dane.cbegin(), dane.cend(), reg);
    sregex_iterator end;
    for_each(beg, end, [](const smatch& m) {
        cout << m.str(1) << " ";
    });
}