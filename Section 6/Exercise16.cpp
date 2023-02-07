// Zadanie 16 - Magazyn. Posiadasz spis wszystkich rzeczy umeiszczonych na skladzie w postaci vector<string>. Musisz te wszystkie rzeczy zadeklarowac, a uszkodzone - wyrzucic. Za pomoca obiektow funkcyjnych
// zadeklaruj (wpisz " - udokumentowane" po kazdej rzeczy) kazdy przedmiot. Ale przed tym rowniez za pomoca obiektu funkcyjnego usun z tego konteneru uszkodzone rzeczy (maja przydomek "uszkodzony").
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
//******************************************************************************************************************************************************
vector<string> spis = {"uszkodzony magnetofon", "kaseta", "uszkodzony glosnik", "telewizor", "telefon", "uszkodzony stol", "krzeslo", "lozko", "lampa"};

//******************************************************************************************************************************************************
class AddStringAfter {
    private:
        string what;
    public:
        AddStringAfter(string str) : what(str) {}

        string operator() (string text) {
            return text + what;
        }
};

//******************************************************************************************************************************************************
class RemoveIfString
{
    private:
        string what;
    public:
        RemoveIfString(string str) : what(str) {}

        bool operator() (string text) {
            if(text.find(what) == string::npos) {
                return false;
            }
            else {
                return true;
            }
        }
};

//******************************************************************************************************************************************************
void wypisz(vector<string>& wekt) {
    for(const auto& elem : wekt) {
        cout << elem << ", ";
    }
    cout << endl;
}

//******************************************************************************************************************************************************
int main()
{
    cout << "Przed usunieciem: ";
    wypisz(spis);

    spis.erase(remove_if(spis.begin(), spis.end(), RemoveIfString("uszkodzony")), spis.end());
    cout << "Po usunieciu: ";
    wypisz(spis);

    transform(spis.cbegin(), spis.cend(), spis.begin(), AddStringAfter(" - udokumentowane"));
    cout << "Po deklaracji: ";
    wypisz(spis);
}