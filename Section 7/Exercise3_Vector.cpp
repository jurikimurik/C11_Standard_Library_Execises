// Zadanie 3 - Sprawdzenie wydajnosci. Stworz vector<int> z losowymi liczbami o ilosci 100000. Nastepnie stworz kopię tego vectora. Od tego momentu zacznij zmierzac czas dla jednego przypadku: Wstaw
// wszystkie elementy drugiego wektora do wektora pierwszego za pomoca push_back i wypisz czas. Nastepnie przywroc stary vector do poczatkowego rozmiaru i zacznij liczyc czas ponownie. Tym razem
// jednak wstaw elementy z drugiego wektora do srodka vectoru pierwszego i wypisz czas.
#include <vector>
#include <chrono>
#include <iostream>
using namespace std;
//*******************************************************************************************************************************************************************************
int main()
{
    srand(time(NULL));
    vector<int> wektor1;
    for (int i = 0; i < 100000; ++i) {
        wektor1.push_back(rand() % 1000);
    }

    vector<int> wektor2(wektor1);

    auto czas = chrono::system_clock::now();
    for (int i = 0; i < wektor2.size(); ++i) {
        wektor1.push_back(wektor2[i]);
    }

    cout << "Czas 1 (w milisekundach): " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << endl;

    wektor1.resize(100000);
    czas = chrono::system_clock::now();

    for (int i = 0; i < wektor2.size(); ++i)
    {
        wektor1.insert(wektor1.begin() + (wektor1.size() / 2), wektor2[i]);
    }

    //NAJLEPSZA METODA:
    //wektor1.insert(wektor1.begin() + (wektor1.size() / 2), wektor2.cbegin(), wektor2.cend());

    cout << "Czas 2 (w milisekudnach): " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - czas).count() << endl;

}