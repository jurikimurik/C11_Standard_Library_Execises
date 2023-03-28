// Zadanie 9 - Inwentaryzacja. Kilka pracownikow muszą policzyć 3600 przedmiotów razem. Każdemu z nich zostaje 
// przydzielona określoną część przedmiotów (ilość), która każdy liczy w swoim tempie i wpisuje ilość przedmiotów 
// do głównego licznika przedmiotów.

#include <mutex>
#include <future>
#include <thread>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

int ile_policzono = 0;
mutex ile_Policzono_Mutex;

class Pracownik
{
    private:
        string imie;

    public:
        Pracownik(string i) : imie(i) {}

        void operator()(int ile_do_policzenia) {
            default_random_engine dre(time(nullptr) + imie.back());
            uniform_int_distribution id(1, 100);

            cout << "Jestem " << imie << "! Zaczynam liczyc!" << endl;
            int zliczono = 0;

            while(zliczono < ile_do_policzenia)
            {
                int zliczono_teraz = id(dre);
                if(zliczono + zliczono_teraz > ile_do_policzenia)
                    zliczono_teraz = ile_do_policzenia - zliczono;

                zliczono += zliczono_teraz;
                this_thread::sleep_for(chrono::milliseconds(id(dre)*10));

                {
                    lock_guard<mutex> lg(ile_Policzono_Mutex);
                    ile_policzono += zliczono_teraz;
                } // zdjecie blokady
                //cout << imie << " zliczyl juz " << zliczono << "/" << ile_do_policzenia << " przedmiotow! " << endl << flush;
            }

            cout << "\n " << imie << " policzyl swoje przedmioty!\n" << endl
                 << flush;
        }
};

int main()
{
    int ilosc_pracownikow = 4;
    int ile_trzeba_policzycz = 3600;

    int rownomierny_przedzial = ile_trzeba_policzycz / ilosc_pracownikow;

    vector<future<void>> futury;
    for (int i = 0; i < ilosc_pracownikow; ++i)
    {
        futury.push_back(async(Pracownik("Numer " + to_string(i+1)), rownomierny_przedzial));
    }

    

    while(true)
    {
        {
            lock_guard<mutex> lg(ile_Policzono_Mutex);
            if(ile_policzono == 3600)
            {
                break;
            } else {
                cout << "Na razie policzono: " << ile_policzono << " z " << ile_trzeba_policzycz << endl
                     << flush;
            }
        }   // zdjecie blokady
        this_thread::sleep_for(chrono::seconds(2));
    }

    for (auto &elem : futury)
    {
        elem.get();
    }

    cout << "Wszystko zostalo policzone! Brawo!" << endl;
}