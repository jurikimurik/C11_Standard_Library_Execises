// Zadanie 23. Niech uzytkownik wprowadzi jakas liczbe typu int64_t. Stworz wizualna animacje, podczas ktorej liczbya naekranie 
//bedzie sie zmieniac 0 do liczby wprowadzonej przez uzytkownika co kilka milisekund
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
//************************************************************************************************************
int main()
{
    cout << "Podaj liczbe: ";
    int64_t liczba;
    cin >> liczba;

    int wspolczynnik = to_string(liczba).size();

    for (int64_t i = 0; i < liczba; i++)
    {
        cout << i;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(10/wspolczynnik));
        cout << '\r';
    }
    cout << endl
         << "Gotowe!";
}