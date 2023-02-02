// Zadanie 19. Wykonaj operacje na ulamkach: 1/3 + 9/2, 8/1-9/123, 34/13*45/3, 15/12 / 23/311, 6/3<5/6, 4/2>5/1.
#include <iostream>
#include <ratio>
using namespace std;
//******************************************************************************************************************


int main()
{
    ratio_add<ratio<1, 3>, ratio<9, 2>> odp1;

    ratio_subtract<ratio<8, 1>, ratio<9, 123>> odp2;

    ratio_multiply<ratio<34, 13>, ratio<45, 3>> odp3;

    ratio_divide<ratio<15, 12>, ratio<23, 311>> odp4;

    ratio_less<ratio<6, 3>, ratio<5, 6>> odp5;

    ratio_greater<ratio<4, 2>, ratio<5, 1>> odp6;



    cout << "Odpowiedz: " << odp1.den << "/" << odp1.num << endl;

    cout << "Odpowiedz: " << odp2.den << "/" << odp2.num << endl;

    cout << "Odpowiedz: " << odp3.den << "/" << odp3.num << endl;

    cout << "Odpowiedz: " << odp4.den << "/" << odp4.num << endl;

    cout << "Odpowiedz: " << boolalpha << odp5.value << endl;

    cout << "Odpowiedz: " << boolalpha << odp6.value << endl;
}