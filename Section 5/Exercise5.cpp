/*Zadanie 5. Stworz kilka wspoldzielnych wskaznikow do dowolnego obiektu. Skorzystaj z niego kilka razy, sprawdz czy w kazdym wskazniku 
wspoldzielonym ta wartosc oryginalna zmiennej sie zmienia. Przeladuj rowniez destruktor tak, zeby wypisywal napis 
"usuwam obiekt pokazywany wskaznikiem" gdy juz ostatni wskaznik przestanie na ten obiekt wskazywac(jak naprzyklad pod koniec programu)*/

#include <iostream>
#include <memory>
using namespace std;
//************************************************************************************************************************************
int main()
{
    shared_ptr<string> wsk1{new string("Arnold"), [](string *p)
                            {
                                cout << "usuwam obiekt pokazywany wskaznikiem" << endl;
                                delete p;
                            }};
    shared_ptr wsk2{wsk1};
    shared_ptr wsk3 = wsk2;

    wsk1->append(" Schwarzenegger Jr.");
    wsk2->pop_back();
    wsk3->pop_back();
    wsk2->pop_back();
    wsk1->pop_back();

    cout << *wsk3 << "-ilosc dowiazan: " << wsk3.use_count() << endl;

    wsk2.reset();

    cout << *wsk3 << "-ilosc dowiazan: " << wsk3.use_count() << endl;
}