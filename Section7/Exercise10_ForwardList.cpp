// Zadanie 10 - Lista spraw. Niech uzytkownik wpisze do programu swoja liczbe spraw w postaci: "1 - trening". Nastepnie posortuj ta liste i wypisz na ekranie. Pozwol uzytkownikowi by mogl usunac lub
// dodac jakas ze spraw. Oprocz tego, moze polaczyc ta liste z nowa lista, ktora moze wpisac ponownie. Wtedy rowniez cala nowa lista musi byc posortowana.
#include <forward_list>
#include <iostream>
using namespace std;
//****************************************************************************************************************************************************
void wypisz(forward_list<string>& lista, bool sortuj = true) {
    if(sortuj)
        lista.sort();
    for (const auto &elem : lista)
    {
        cout << elem << "\n";
    }
    cout << endl;
}

//****************************************************************************************************************************************************
bool wpisz_sprawe(forward_list<string> &lista)
{
    cout << "Wpisz swoja sprawe lub zadanie w postaci \'1 - trening\' (wpisz q zeby skonczyc): ";
    string wpr;
    getline((cin >> ws), wpr);
    if (wpr == "q")
    {
        return false;
    }

    lista.push_front(wpr);
    return true;
}

//****************************************************************************************************************************************************
int main()
{
    forward_list<string> lista_spraw;

    while (wpisz_sprawe(lista_spraw));

    cout << "Po sortowaniu: \n";
   
    

    while(true) {
        wypisz(lista_spraw);
        cout << "Usunac pierwsza sprawe - 'r', dodac sprawy(e) - 'a', dodac nowa liste spraw - 'l', wyjsc - 'q': ";
        char znak;
        cin >> znak;

        forward_list<string> nowa_lista; // opcjonalna

        switch (znak)
        {
        case 'r':
            lista_spraw.pop_front();
            if(lista_spraw.empty()) {
                return 0;
            }
            break;
        case 'a':
            while (wpisz_sprawe(lista_spraw));
            break;
        case 'l':
            while(wpisz_sprawe(nowa_lista));

            cout << "Nowa lista spraw: \n";
            wypisz(nowa_lista, true);

            cout << "Po polaczeniu: \n";
            lista_spraw.merge(nowa_lista);
            break;
        case 'q':
            return 0;
            break;

        default:
            break;
        }
    }
}