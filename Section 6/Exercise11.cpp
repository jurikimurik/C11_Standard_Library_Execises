// Zadanie 11. Usuwanie z kontenerow alokacyjnych i nieporzadkujacych. Masz podany kontener set<int> z wartosciami {2,3,5,1,2,3,4,3,1,2,2,3,4,2}. Usun z niego wszystkie dwojki za pomoca dowolnego sposobu.
 #include <unordered_set>
 #include <algorithm>
 #include <iostream>
using namespace std;
//************************************************************************************************************************
int main()
{
    unordered_set<int> liczby = {2, 3, 5, 1, 2, 3, 4, 3, 1, 2, 2, 3, 4, 2};
    liczby.erase(2);
    for(const auto& elem: liczby) {
        cout << elem << ", ";
    }
    cout << endl;
}