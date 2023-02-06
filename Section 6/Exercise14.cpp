// Zadanie 14 - Wielkie Sprzatanie. Posiadasz koneter deque<string>, ktory miesci w sobie wiele mebli dostepnych w pokoju. Jednak dodaj w losowe miejsca tego pokoju "Karaluch". Wypisz powstaly kontener na
// ekranie a nastepnie "zadzwon po inspektora" i usun wszystkich karaluchow. (Skorzystaj z algorytmow i lambdy do okreslenia czy podany obiekt jest karaluchiem).
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
//********************************************************************************************************************************************************************
deque<string> pokoj = {"Lozko", "Szafa", "Stol", "Krzeslo", "Monitor", "Okno", "Telewizja", "Wielkie krzeslo", "Maly stolik", "Polki"};
//********************************************************************************************************************************************************************
int main()
{
    srand(time(NULL));
    for (int i = 0, los = rand() % pokoj.size(); i < los; i++) {
        auto iter = pokoj.begin() + rand() % pokoj.size();
        pokoj.insert(iter, "Karaluch");
    }

    cout << "Zawartosc pokoju przed sprzataniem: ";
    for (const auto &elem : pokoj)
    {
        cout << elem << ", ";
    }
    cout << endl;

    cout << "\nDzwonimy po inspektora!" << endl;

    pokoj.erase(remove_if(pokoj.begin(), pokoj.end(), [](string cos)
              {
        if(cos == "Karaluch") {
            return true;
        } else {
            return false;
        } }), pokoj.end());

        
    cout << endl;

    cout << "Zawartosc pokoju po sprzataniu: ";
    for (const auto &elem : pokoj)
    {
        cout << elem << ", ";
    }
    cout << endl;
}