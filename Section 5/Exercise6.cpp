/*Zadanie 6. Stworz klase Pracownik, ktory bedzie wskazywac na wszystkich swoich podrzednych i nadrzednych. Wykorzystaj do
tego shared_ptr. Rowniez stworz initCech(), ktrozy zwraca shared_ptr<Pracownik>, ktory stworzy pracownika i przypisze mu
poperzednio stworzonych nadrzednych i jednego podrzednego.
Sprawdz czy te obiekty poprawnie sie usuwaja. Jezeli nie, to wykorzystaj do tego weak_ptr i sprawdz ponownie.*/

#define STARA_METODA false

#include <iostream>
#include <memory>
#include <vector>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Pracownik {
    public:
        string imie;
        shared_ptr<Pracownik> nadrzedny;
        #if STARA_METODA == true
        
        vector<shared_ptr<Pracownik>> podrzedni;
        #else
        vector<weak_ptr<Pracownik>> podrzedni;
        #endif

        Pracownik(string n) : imie{n} {}

        ~Pracownik() {
            cout << "usuwam pracownika " << imie << endl;
        }
};
//******************************************************************************************************************************

shared_ptr<Pracownik> initCech() {
        shared_ptr<Pracownik> Pawel{new Pracownik("Pawel")};

        shared_ptr<Pracownik> Andrzej(new Pracownik("Andrzej"));
        shared_ptr<Pracownik> Maks(new Pracownik("Maksymilian"));
        shared_ptr<Pracownik> Wojtyla(new Pracownik("Wojtyla"));

        Andrzej->podrzedni.push_back(Pawel);

        Pawel->nadrzedny = Andrzej;
        Pawel->podrzedni.push_back(Wojtyla);

        return Pawel;
}

//******************************************************************************************************************************
int main()
{
        shared_ptr<Pracownik> Pawel = initCech();

        cout << "Jest pracownik: " << Pawel->imie << "\n\n";
        cout << "Jego nadrzedni: ";
#if STARA_METODA == true
        cout << Pawel->nadrzedny->imie;
#else
        cout << Pawel->nadrzedny->imie;
#endif
        cout << endl;
}