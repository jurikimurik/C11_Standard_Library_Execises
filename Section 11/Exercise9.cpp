// Zadanie 9 - Magazyn skrzyn. Posiadasz magazyn skrzyn w ktorym kazda skrzynia jest reprezentowana liczbą losową. Pozwol uzytkownikowi
// zliczyc interesujace go skrzynie za pomoca podania liczby, ktora musi byc wieksza niz interesujace go skrzynie. Niech takze bedzie w
// stanie znalezc okreslony ciag skrzyn (liczb) na pozycjach (wypisz pozycje) lub pozycje powtarzajacych sie skrzyn wedlug numeru.
#include <vector>
#include <iostream>
using namespace std;
//****************************************************************************************************************
vector<int> generuj_skrzynie(int ile, int od, int az_do)
{
    srand(time(NULL));
    vector<int> liczby;
    while(ile-- != 0)
    {
        liczby.push_back(rand() % (az_do - od) + od);
    }
    return liczby;
}
//****************************************************************************************************************
void wypisz_skrzynie(const vector<int>& skrzynie)
{
    for(const auto& elem : skrzynie)
    {
        cout << elem << ", ";
    }
    cout << endl;
}
//****************************************************************************************************************
int main()
{
    vector<int> skrzynie = generuj_skrzynie(20, 8, 10);

    wypisz_skrzynie(skrzynie);

    cout << "Podaj ID, wedlug ktorego wszystkie mniejsze skrzynie zostana policzone: ";
    int mniejsze_od;
    cin >> mniejsze_od;

    int ilosc = count_if(skrzynie.begin(), skrzynie.end(),
                         [&mniejsze_od](int elem)
                         {
                             return elem < mniejsze_od;
                         });

    cout << "Takich skrzyn jest: " << ilosc << endl;

    cout << "Teraz podaj okreslony ciag liczb i zakoncz znakiem 'q':";
    vector<int> podciag;
    while(cin)
    {
        int liczba;
        cin >> liczba;
        podciag.push_back(liczba);
    }
    podciag.pop_back();
    cin.clear();
    cin.ignore();

    auto pos = search(skrzynie.begin(), skrzynie.end(), podciag.begin(), podciag.end());
    while(pos != skrzynie.end())
    {
        cout << "podciag znaleziony na pozycji " << distance(skrzynie.begin(), pos) + 1 << " ." << endl;

       //++pos;
        pos = search(++pos, skrzynie.end(), podciag.begin(), podciag.end());
    }

    cout << "Teraz podaj okreslony ID, ktory sie powtarza pod rzad: ";
    int id_powtorzen;
    cin >> id_powtorzen;
    cout << "Oraz jak ile razy id powtarza sie pod rzad: ";
    int id_ile;
    cin >> id_ile;

    pos = search_n(skrzynie.begin(), skrzynie.end(), id_ile, id_powtorzen);
    while(pos != skrzynie.end())
    {
        cout << "ciag znaleziony na pozycji " << distance(skrzynie.begin(), pos) + 1 << "." << endl;
        pos = search_n(++pos, skrzynie.end(), id_ile, id_powtorzen);
    }
}