/*Zadanie 7. Stworz dwa wspoldzielone wskazniki na obiekt string("Natasza") oraz jeden na obiekt string("Igor"). Sprawdz liczbe dowiazan 
do kazdego z nich. Nastepnie przypisz wszystkie do obiektu string("Igor") i sprawdz ile teraz wskaznikow wskazuje na obiekt string("Igor").*/

#include <iostream>
#include <memory>
using namespace std;
//************************************************************************************************************************
int main()
{
   
    shared_ptr<string> Wladyslaw{new string("Natasza"), [](string *p)
                                 {
                                     cout << "Nikt juz sie nie interesuje Natasza " << endl;
                                 }};
    shared_ptr<string> Olek(Wladyslaw); // tez "Natasza"
    weak_ptr<string> Kujon{Wladyslaw};

    shared_ptr<string> Weronika{new string("Igor")};

    cout << "Dla " << *Wladyslaw << ": " << Wladyslaw.use_count() << endl;
    cout << "Dla " << *Weronika << ": " << Weronika.use_count() << endl;

    if (!Kujon.expired())
        cout << "Kujon tez interesuje sie Natasza, ale boi sie do niej podejsc! " << endl;

    cout << "\n----Zmieniamy zainteresowania (po kilku gozinach)----\n" << endl;

    Wladyslaw = Weronika;
    Olek = Weronika;

    cout << "Dla " << *Weronika << ": " << Weronika.use_count() << endl;

    if(Kujon.expired())
        cout << "Kujon pamieta o Nataszy, ale ta juz zdazyla uciec, gdyz nikt sie nia nie interesowal na powaznie! " << endl;
}