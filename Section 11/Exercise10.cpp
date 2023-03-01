// Zadanie 10 - Analizator slowa. Niech uzytkownik wprowadzi slowo. Pozwol mu: zwiekszyc wszystkie litery w nim / zmniejszyc. Oraz pozwol
// mu znajezc najmniejszy wedlug alfabetu znak i najwiekszy oraz wypisz go i jego pozycje.
#include <iostream>
#include <algorithm>
using namespace std;
using namespace std::placeholders;
//******************************************************************************************************************************
int main()
{
    
    cout << "Wprowadz slowo: ";

    string slowo;
    getline((cin >> ws), slowo);

    cout << "Chcesz zwiekszyc (1) czy zmniejszyc (2) cale slowo?: ";
    int odpowiedz;
    cin >> odpowiedz;

    int (*wsk)(int);
    if (odpowiedz == 1)
    {
        wsk = toupper;
        
    } else {
        wsk = tolower;
    }
    for_each(slowo.begin(), slowo.end(),
             [&wsk](char &c)
             {
                 c = wsk(c);
             });
    cout << "Slowo zmodyfikowane: " << slowo << endl;

    auto para = minmax_element(slowo.begin(), slowo.end());
    cout << "Najmniejsza litera (wedlug alfabetu): " << *para.first << endl;
    cout << "Najwieksza litera (wedlug alfabetu): " << *para.second << endl;
}