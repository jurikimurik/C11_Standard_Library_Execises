// Zadanie 18. Stworz klase LZ, w ktorej zdefinujesz operator porownywania == oraz operator <. Nastepnie w funkcji main
// za pomoca przestrzeni nazwa std::rel_ops porownaj dwa obiekty LZ za pomoca operatorow >=, <=, >, !=. Kazde dzialanie przetestuj.
#include <iostream>
#include <utility>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class LZ {
    int liczba_rzeczywista;
    std::string liczba_urojona;
public:
    bool operator==(const LZ & arg1) const
    {
        bool spr1 = liczba_rzeczywista == arg1.liczba_rzeczywista;
        bool spr2 = liczba_urojona == arg1.liczba_urojona;

        return (spr1 && spr2);
    }

    bool operator<(const LZ & arg1) const
    {
        return liczba_rzeczywista < arg1.liczba_rzeczywista;
    }

    LZ(int liczba, std::string uroj) : liczba_rzeczywista(liczba), liczba_urojona(uroj) {}
};
//************************************************************************************************************************************
int main()
{
    LZ liczba1(1, "4i");
    LZ liczba2(-1, "-3i");

    using namespace std::rel_ops;
    using std::cout;
    using std::endl;
    cout << std::boolalpha;
    cout << (liczba1 == liczba2) << endl;
    cout << (liczba1 < liczba2) << endl;
    //korzystamy z rel_ops
    cout << (liczba1 >= liczba2) << endl;
    cout << (liczba1 <= liczba2) << endl;
    cout << (liczba1 > liczba2) << endl;
    cout << (liczba1 != liczba2) << endl;
}