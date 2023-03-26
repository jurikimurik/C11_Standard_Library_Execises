// Zadanie 2 - BIMBA. Stwórz kilka wątków zaśmiecających pamięć i przechwyć wyjątek, który będzie pochodzić od jednego z tych 
// wątków i skończ działanie programu.
#include <future>
#include <thread>
#include <vector>
#include <iostream>
using namespace std;

void zasmiec_pamiec(char c)
{
    vector<long double> liczby_niepotrzebne;
    while(true)
    {
        for (long double i = 0; i < 1000000; ++i)
        {
            liczby_niepotrzebne.push_back(i);
        }
        cout.put(c).flush();
    }
}

int main()
{
    cout << "NIECH ZACZNIE SIE ZASMIECANIE!" << endl;

    int ilosc_watkow = 50;
    vector<future<void>> watki_smietnikowe;
    for (int i = 0; i < ilosc_watkow; ++i)
    {
        watki_smietnikowe.push_back(async(zasmiec_pamiec, (char)i+65));
    }

    try {
        for (auto &elem : watki_smietnikowe)
        {
            elem.get();
        }
    } catch (const exception& e) {
        cerr << "WYJATEK: " << e.what() << endl;
    }
}