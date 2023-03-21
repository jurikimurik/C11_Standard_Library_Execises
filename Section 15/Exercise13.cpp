// Zadanie 13 - Swoją kicia. Stwórz własną klasę Kot, która będzie posiadać imię oraz wiek. Zdefiniuj rozszerzony operator>> oraz operator<< dla tej klasy i sprawdź jego działanie. 
//Operator<< extended
//Operator>> extended
#include <iostream>
#include <sstream>
using namespace std;

struct Kot {
    string imie;
    int wiek;
};


template <typename charT, typename traits>
inline
std::basic_ostream<charT, traits>&
operator<< (std::basic_ostream<charT, traits>& strm, const Kot& f)
{
    // strumien dla lancucha
    // - z tym samym formatem
    // - bez okreslonej specjalnej szerokosci pola
    std::basic_ostringstream<charT, traits> s;
    s.copyfmt(strm);
    s.width(0);

    // wypelnij strumien
    s << f.imie << " - " << f.wiek << " lat";

    // wypisz strumien
    strm << s.str();

    return strm;
}

template <typename charT, typename traits>
inline
std::basic_istream<charT,traits>&
operator >> (std::basic_istream<charT, traits>& strm, Kot& f)
{
    string imie;
    int wiek;

    strm >> imie;

    // jesli dostepny
    // - odczytaj znak '-' oraz wartosc wieku
    char znak;
    strm >> znak >> wiek;

    // jesli do tej chwili wszystkie operacje zostaly wykonane poprawnie
    // zmien wartosc mianownika
    if(strm) {
        f = Kot{imie, wiek};
    }

    string pozostalosci;
    strm >> pozostalosci;

    return strm;
}

int main()
{
    Kot Waldus{"Waldek", 10};
    Kot Puchatek{"Puchatek", 3};

    cout << Waldus << endl
         << Puchatek << endl;

    Kot Nowy;

    cin >> Nowy;

    cout << Nowy;
}
