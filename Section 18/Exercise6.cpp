// Zadanie 6 - Dzieciaki. Każdy z pięciu dzieciaków musi zaśpiewać swój dźwięk dziesięć razy. 
// Muszą to robić mniej więcej jednocześnie, gdy nauczyciel podniesie rękę w górę.
#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <iostream>
#include <exception>
using namespace std;

void spiewaj(char c)
{
    default_random_engine dre(c);
    uniform_int_distribution di(10, 1000);

    auto czas = chrono::system_clock::now();
    while (chrono::system_clock::now() < czas + chrono::seconds(10))
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(di(dre)));
    }
}

int main()
{
    cout << "Gdy bedziesz gotow, podnies reke (wpisz cokolwiek): ";
    cin.get();

    char zbior[] = {'A', 'O', 'E', 'I', 'U'};

    vector<thread> watki;
    for (int i = 0; i < 5; ++i)
    {
        watki.push_back(thread(spiewaj, zbior[i]));
    }

    for(auto& elem : watki)
    {
        elem.join();
    }

    cout << "\nOpuscilesz reke nie potrafiac wytrzymac halasu!" << endl;
}