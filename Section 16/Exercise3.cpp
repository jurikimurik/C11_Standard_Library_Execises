// Zadanie 3 - Głupia lokalizacja. Stwórz klasę glupiaLokalizacja, która zmieni aspekt wypisywania liczb w dziwny sposób. Następnie 
// skorzystaj z tego aspektu, żeby wypisać jednak zwykła liczbę wielka i jedna zmiennoprzecinkowa.
#include <locale>
#include <iostream>
using namespace std;

class glupiaLokalizacja : public numpunct_byname<char> {
    public:
    glupiaLokalizacja(const string& name) : numpunct_byname<char>(name) {}

    protected:
    virtual string do_truename() const {
        return "elo, gosciu";
    }

    virtual string do_falsename() const {
        return "haha glupek";
    }

    virtual glupiaLokalizacja::char_type do_decimal_point() const {
        return '+';
    }

    virtual glupiaLokalizacja::char_type do_thousands_sep() const {
        return '|';
    }

    virtual glupiaLokalizacja::string_type do_grouping() const {
        return {2, 0};
    }
};

int main()
{
    long double liczba_zwykla = 124242.23;
    long double liczba_niezwykla = 12.42342;

    cout.imbue(locale(locale(""), new glupiaLokalizacja("")));

    cout << "Wypisuje liczbe zwykla: " << liczba_zwykla << endl;
    cout << "Wypisuje liczbe niezwykla: " << liczba_niezwykla << endl;
    cout << "Sprawdzamy true i false: " << boolalpha << true << "/" << false << endl;
}