// Zadanie 8 - Stwórz obiekty funkcyjne, które będą reprezentować zawodnika 
// (muszą mieć imię/prędkość maksymalna-minimalna). Następnie uruchom te 
// wszystkie obiekty jednocześnie i sprawdź który przybiegnie jako pierwszy.
#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <iostream>
using namespace std;

class Zawodnik {
    private:
        int przebieglem = 0;

    public:
        string imie;
        int szybkosc_min;
        int szybkosc_max;

        Zawodnik(string i, int m, int x) : imie(i), szybkosc_min(m), szybkosc_max(x)
        {
            cout << "Jestem " << imie << "! Biegam z szybkoscia: " << szybkosc_min << " - " << szybkosc_max << "!" << endl;
        }

        void operator()(int jaki_cel, bool* czy_ktos_zdarzyl)
        {
            default_random_engine dre(time(nullptr));
            uniform_int_distribution di(szybkosc_min, szybkosc_max);

            cout << imie << " rusza!" << endl << flush;
            while(przebieglem < jaki_cel)
            {
                przebieglem += di(dre);
                this_thread::sleep_for(chrono::milliseconds(di(dre)*10));
            }

            if(*czy_ktos_zdarzyl == false)
            {
                *czy_ktos_zdarzyl = true;
                cout << "Kowboj " << imie << " wygrywa!" << endl;
            } else {
                cout << "Kowboj " << imie << " przegrywa!" << endl;
            }

        
        }
};

void hello(char c)
{
        srand(time(nullptr));

        for (int i = 0; i < 10; ++i)
        {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(rand() % 100));
        }
            
}

int main()
{
        cout << "Witamy zawodnikow!" << endl;

        Zawodnik alfred("Alfred", 4, 10);
        Zawodnik gibraltar("Gibraltar", 1, 12);
        Zawodnik maks("Maks", 5, 8);
        Zawodnik andrzej("Andzrej", 3, 11);
        Zawodnik kura("Kura", 1, 5);

        cout << "\n\nNiech zaczna sie wyscigi!" << endl;
        bool czyJakisZwyciezyl = false;

        vector<Zawodnik> zawodnicy = {alfred, gibraltar, maks, andrzej, kura};
        vector<future<void>> futury;
        for (auto &elem : zawodnicy)
        {
            futury.push_back(move(async(elem, 50, &czyJakisZwyciezyl)));
        }

        for(auto& elem : futury)
        {
            elem.get();
        }
}