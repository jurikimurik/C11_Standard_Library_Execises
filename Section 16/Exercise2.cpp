// Zadanie 2 - Spolszczenie. Stwórz klasę polishLocalization w którym wartościom logicznym używanym przez aspekt będziesz 
// przypisywał wartości „prawda” lub „fałsz”. Zamień również parametr grouping oraz decimal_point.
#include <locale>
#include <iostream>
using namespace std;

class polishLocalization : public numpunct_byname<char> {
    public:
        polishLocalization (const string& name) : numpunct_byname<char> (name) {}
    protected:
        virtual string do_truename() const {
            return "prawda";
        }

        virtual string do_falsename() const {
            return "falsz";
        }
        
        virtual polishLocalization::char_type do_decimal_point() const {
            return '?';
        }

        virtual polishLocalization::string_type do_grouping() const {
            return {3, 0};
        }
};

int main()
{
        cout.imbue(locale(locale("pl_PL"), new polishLocalization("pl_PL")));
        long double liczba = 1241252.23;
        cout << "Wypisuje liczbe zgodnie z zadanym aspektem: " << liczba << " " << boolalpha << endl;

        cout << "Czy jade pociagiem? " << true << endl;
}