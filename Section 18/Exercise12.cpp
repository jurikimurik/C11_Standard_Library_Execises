// Zadanie 12 - Potwory. Na błocie mieszkają potwory, co czuwają aż jakiś człowiek wkroczy na ich teren. W odstępach 
// losowych czasu na błoto wkracza 10 ludzi. Wtedy wszystkie potwory rzucają się na niego, ale dostaje jego ciało tylko 
// jeden potwór. Skorzystaj ze zmiennych warunkowych.
#include <condition_variable>
#include <mutex>
#include <future>
#include <thread>
#include <random>
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int ilosc_ofiar = 10;
mutex io_mutex;

class Ofiara
{
    string imie;

public:
    Ofiara(string i) : imie(i) {}
};

vector<Ofiara> ludzie = {};

mutex cJK_mutex;
condition_variable czyJestKtosNaBlocie;



class Potwor
{
        string imie;
        string co_zwykle_robi;
        string kiedy_wie_o_ofierze;
        string kiedy_zlapala;

        public:
            Potwor(string i, string c, string kw, string kz) : imie(i), co_zwykle_robi(c), kiedy_wie_o_ofierze(kw), kiedy_zlapala(kz) {}

            void operator()()
            {
                default_random_engine dre(time(nullptr));
                uniform_int_distribution id(1, 2000);
                while (true)
                {
                    {
                    cout << imie << " " << co_zwykle_robi << endl << flush;
                    unique_lock<mutex> ul(cJK_mutex);
                    czyJestKtosNaBlocie.wait(ul, []
                                             { return !ludzie.empty(); });
                    }

                    cout << imie << " " << kiedy_wie_o_ofierze << endl
                         << flush;

                    this_thread::sleep_for(chrono::milliseconds(id(dre)));
                    {
                        lock_guard<mutex> lg(cJK_mutex);

                        if(!ludzie.empty())
                        {
                            cout << imie << " " << kiedy_zlapala << "\n\n" << endl << flush;
                            ludzie.pop_back();
                            lg.~lock_guard();
                        }
                        if(ilosc_ofiar == 0)
                        {
                            return;
                        }
                    }
                }
            }
};

int main()
{
    Potwor BabaJaga("Baba Jaga", "czeka w swoim domku.", "wysyla swoich podopiecznych!", "bedzie miala dzis pyszny obiad.");
    Potwor Leszy("Leszy", "czeka sposrod drzew.", "rusza!", "upolowal swoja ofiare.");
    Potwor Wilkolak("Wilkolak", "spi w swojej jaskini.", "uslyszal cos i ruszyl!", "wciaga swoja ofiare do jaskini.");
    Potwor Utopiec("Utopiec", "spoczywa w wodzie.", "wyczul ruch i juz plynie!", "zabral nieznajomego na dno.");

    auto BJf = async(BabaJaga);
    auto Lf = async(Leszy);
    auto Wf = async(Wilkolak);
    auto Uf = async(Utopiec);

    this_thread::sleep_for(chrono::seconds(1));

    while(ilosc_ofiar > 0)
    {
                lock_guard<mutex> lg(cJK_mutex);
                cout << "Nieznajomy wkroczyl na teren blotnisty..." << endl;
                ludzie.push_back(Ofiara("Nieznajomy "));
                lg.~lock_guard();
                czyJestKtosNaBlocie.notify_all();
                {
                    lock_guard<mutex> lg2(io_mutex);
                    ilosc_ofiar--;
                }
                this_thread::sleep_for(chrono::seconds(5));
                
    }

    cout << "Nie ma wiecej chetnych... " << endl;

    BJf.get();
    Lf.get();
    Wf.get();
    Uf.get();
}