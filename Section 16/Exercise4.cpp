// Zadanie 4 - Cyber-money. Stwórz klasę cyebrpunktMoney, która zmieni aspekt wypisywania wartości pieniężnych w taki sposób,
// żeby przypominało wartości pieniężne z Cyberpunk. Następnie korzystając z tego wypisz jakakolwiek kwotę pieniężną.
#include <locale>
#include <iostream>
#include <iomanip>
using namespace std;

class cyberpunkMoney : public moneypunct_byname<char>
{
public:
    cyberpunkMoney(const string &name) : moneypunct_byname<char>(name) {}

private:
    using typ_c = cyberpunkMoney::char_type;
    using typ_s = cyberpunkMoney::string_type;

protected:
    virtual typ_c do_decimal_point() const
    {
        return '\0';
    }
    virtual typ_c do_thousands_sep() const
    {
        return '\0';
    }
    virtual typ_s do_curr_symbol() const
    {
        return "€$";
    }
};

int main()
{
    long double pieniadze = 1500750;
    cout.imbue(locale(locale("pl_PL"), new cyberpunkMoney("pl_PL")));

    cout << showbase << fixed;
    cout << "Pieniadze jak w Cyberpunk'u: " << put_money(pieniadze) << endl;
}