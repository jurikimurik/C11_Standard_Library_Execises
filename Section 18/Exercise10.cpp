// Zadanie 10 - Wspólną baza danych. Stwórz klase reprezentująca bazę danych. Nastepnie będą trzy watki, które będą wpisywać 
// tam ID przedmiotów, zliczać ilość przedmiotów oraz wypisywać jakie id zostały wpisane do bazy danych. Metody muszą używać 
// wspólnego obiektu.

#include <mutex>
#include <future>
#include <thread>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

class DataBase
{
    private:
        vector<int> items_id;
        recursive_mutex items_id_mutex;
    public:
        void show_items_id()
        {
            {
                lock_guard<recursive_mutex> lg(items_id_mutex);
                for(const auto& elem : items_id)
                {
                    cout << elem;
                    if(elem != items_id.back())
                        cout << ", ";
                }
                cout << endl << flush;
            }
        }

        void add_item_by_id(int id)
        {
            lock_guard<recursive_mutex> lg(items_id_mutex);
            items_id.push_back(id);
        }

        void count_items()
        {
            lock_guard<recursive_mutex> lg(items_id_mutex);
            show_items_id();
            cout << "Ilosc: " << items_id.size() << endl
                 << flush;
        }
};

void thread_plus(DataBase& baza)
{
        for (int i = 0; i < 25; ++i)
        {
            baza.add_item_by_id(i);
            this_thread::sleep_for(chrono::milliseconds(1));
        }
}

void thread_count(DataBase& baza)
{
        for (int i = 0; i < 10; ++i)
        {
            baza.count_items();
            this_thread::sleep_for(chrono::milliseconds(5));
        }
}

void thread_print(DataBase& baza)
{
        for (int i = 0; i < 10; ++i)
        {
            baza.show_items_id();
            this_thread::sleep_for(chrono::milliseconds(3));
        }
}

int main()
{
        DataBase baza;
    

        auto f1 = async(thread_plus, ref(baza));
        auto f2 = async(thread_count, ref(baza));
        auto f3 = async(thread_print, ref(baza));

        f1.get();
        f2.get();
        f3.get();

        baza.count_items();
}