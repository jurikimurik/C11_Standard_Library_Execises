// Zadanie 20 - Turbo-huragan. Użytkownik podaje słowo, które w zależności od losowości zostaje zmienione w trzy sposoby: może się odwrócić, 
// przemieścić się lub zostać spermutowane lub to wszystko na raz.
#include <algorithm>
#include <iostream>
using namespace std;

void huragan(string& slowo)
{
    srand(time(NULL));

    bool losowosc = rand() % 2;
    if(losowosc)
    {
        reverse(slowo.begin(), slowo.end());
    }

    losowosc = rand() % 2;
    if(losowosc)
    {
        auto pos = slowo.begin() + rand() % slowo.size();
        rotate(slowo.begin(), pos, slowo.end());
    }

    losowosc = rand() % 2;
    if(losowosc)
    {
        next_permutation(slowo.begin(), slowo.end());
    }
}

int main()
{
    string slowo;
    cout << "Podaj slowo: ";
    getline(cin, slowo);

    huragan(slowo);

    cout << "O cholera! Uragan trochę zmienil twoje slowo: " << slowo;
}