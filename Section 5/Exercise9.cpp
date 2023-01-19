/*Zadanie 9. Stworz funkjce typu void o nazwie zlew(...) przyjmujaca unikalny wskaznik. Oraz funkcje daj_miejsce(), ktora zwraca nowy
unikalny wskaznik do obiektu string. Przetestuj ich. Nastepnie stworz tabele wektorow takich wskaznikow, ktora musi byc uzupelniona
10-ma wskaznikami z metody daj_miejsce(). Nastepnie usun kazdy z tych wskaznikow wysylajac ich do funkcji zlew pojedynczo.*/

#include <iostream>
#include <memory>
#include <vector>
using namespace std;
//***************************************************************************************************************
template <typename T>
void zlew(unique_ptr<T> arg) {
    cout << "Zmywamy to, co nam przekazali: " << *arg << endl;
}
//***************************************************************************************************************
unique_ptr<string> daj_miejsce() {
    cout << "Masz tu miejsce z inikalnym stringiem: KAWABUNGA" << endl;

    return unique_ptr<string>(new string("KAWABUNGA"));
}
//***************************************************************************************************************
int main()
{
    auto kwabunga = daj_miejsce();

    zlew(std::move(kwabunga));

    using super_typ = decltype(daj_miejsce());
    vector<super_typ> tabela;
    for (int i = 0; i < 10; i++)
    {
        tabela.push_back(daj_miejsce());
    }

    cout << "Dlugosc tabeli: " << tabela.size() << endl;

    for (int inx = 0;  auto &elem : tabela)
    {
        cout << (inx++) << ": " << *elem << endl;
    }

    cout << "--------PODDAJEMY UTYLIZACJI--------" << endl;

    for(auto &elem : tabela)
    {
        zlew(std::move(elem));
    }
    tabela.clear();

    cout << "Dlugosc tabeli teraz: " << tabela.size() << endl;
}