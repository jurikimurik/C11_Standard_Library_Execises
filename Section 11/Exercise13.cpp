// Zadanie 13 - Slownik. Uzytkownik wpisuje slowa. Nastepnie zotaja oni posortowane. Uzytkownik moze sprawdzic czy spelniaja okreslone
// kreyterium: zawieraja jakas litere/koncza sie na okreslona litere.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//****************************************************************************************************************************************
vector<string> pobierz_slowa()
{
    vector<string> slowa;

    cout << "Wprowadzaj slowa rozdzielajac ich przyciskiem ENTER a konczac wprowadzajac q: ";
    while (true)
    {
        string slowo;
        getline(cin, slowo);
        if(slowo == "q")
            break;
        slowa.push_back(slowo);
    }

    return slowa;
}
//****************************************************************************************************************************************
decltype(auto) sprawdz_zawartosc(char zn)
{
    return [zn](string slowo)
    { return slowo.find(zn) != string::npos; };
}
//****************************************************************************************************************************************
decltype(auto) sprawdz_koncowki(char zn)
{

    return [zn](string slowo)
    { return *prev(slowo.end()) == zn; };
}
//****************************************************************************************************************************************
void sprawdz(int odp, vector<string> &slowa)
{
    cout << "Wprowadz interesujaca cie litere: ";
    char litera;
    cin >> litera;

    auto lambda_p = sprawdz_zawartosc(litera);
    auto lambda_d = sprawdz_koncowki(litera);

    cout << boolalpha;

if(odp == 1)
{
        cout << "Czy zawieraja wszyscy? " << all_of(slowa.begin(), slowa.end(), lambda_p) << endl;
        cout << "Czy zawiera jakikowiek? " << any_of(slowa.begin(), slowa.end(), lambda_p) << endl;
        cout << "Czy nikt nie zawiera? " << none_of(slowa.begin(), slowa.end(), lambda_p) << endl;
} else {
        cout << "Czy zawieraja wszyscy? " << all_of(slowa.begin(), slowa.end(), lambda_d) << endl;
        cout << "Czy zawiera jakikowiek? " << any_of(slowa.begin(), slowa.end(), lambda_d) << endl;
        cout << "Czy nikt nie zawiera? " << none_of(slowa.begin(), slowa.end(), lambda_d) << endl;
}
    
}
//****************************************************************************************************************************************
int main()
{
    vector<string> slowa = pobierz_slowa();

    for(const auto& elem : slowa)
    {
        cout << elem << endl;
    }

    cout << "Sprawdz kryterium(1 - zawieraja jakas litere, 2 - koncza sie na okreslona litere): ";
    int odpowiedz;
    cin >> odpowiedz;

    sprawdz(odpowiedz, slowa);
}