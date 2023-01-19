/*Zadanie 8. Stworz wskaznik unikalny o nazwie zapalka dla obiektu string("ogien"). Na dwa sposoby zmien zawartosc obiektu tak, zeby w 
wyniku twoich dzialan "ogien" zamienil sie w "OGIEN". Nastepnie przepisz to do innego unikalnego wskaznika galaz podczas inicjalizacji.
Na koniec przypisz ten obiekt do unikalnego wskaznika drzewo, ktory byl zdefiniowany wczesniej. */

#include <iostream>
#include <memory>
using namespace std;
//************************************************************************************************************************
int main()
{
    unique_ptr<string> zapalka(new string("ogien"));

    cout << "Było: " << *zapalka << endl;

    (*zapalka)[0] = 'O';
    (*zapalka)[1] = 'G';
    zapalka->replace(2, 3, "IEN");

    cout << "Stało: " << *zapalka << endl;

    unique_ptr<string> galaz (zapalka.release());
    
    cout << "Po oddaniu praw:\n\tCzy zapalka ma cos przepisane? " << boolalpha << (zapalka != nullptr)
                    <<"\n\tCzy galaz ma cos przepisane? " << (galaz != nullptr) << endl;

    unique_ptr<string> drzewo;
    swap(galaz, drzewo);

    cout << "--------ZMIANA WLASCICIELA---------\n" << "\tCzy galaz ma cos przepisane? " << boolalpha << (galaz != nullptr)
                << "\n\tA czy drzewo teraz ma przepisane coś? I co to jest?" << (drzewo != nullptr) << ", " << *drzewo << endl; 
}