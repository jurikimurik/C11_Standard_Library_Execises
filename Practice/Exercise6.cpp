// Zadanie 6 - Grafik odwiedzania. Posiadasz spis klientów z godzinami tego, kiedy odwiedzili sklep w pliku klienci_czas.data. Posortuj 
// spis według godzin odwiedzin i wyświetl rezultat na ekranie.
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
using namespace std;

vector<string> posortuj_wedlug_czasu(string nazwa_pliku)
{
    ifstream strm(nazwa_pliku);
    if(!strm)
    {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> dane;
    while(strm)
    {
        string wpis;
        getline(strm, wpis);
        dane.push_back(wpis);
    }

    sort(dane.begin(), dane.end(), [](string &p, string &d)
         {
             istringstream i_p(p);
             istringstream i_d(d);

             string fmt = "%R";

             struct tm czas_p, czas_d;
             i_p >> get_time(&czas_p, fmt.c_str());
             i_d >> get_time(&czas_d, fmt.c_str());

            i_p.clear();
            i_d.clear();

            auto pierwszy = mktime(&czas_p); 
            auto drugi = mktime(&czas_d); 
            
            return pierwszy > drugi;
            });

    return dane;
}

int main()
{
    vector<string> dane = posortuj_wedlug_czasu("klienci_czas.data");

    for (const auto& elem : dane)
    {
        cout << elem << endl;
    }
}