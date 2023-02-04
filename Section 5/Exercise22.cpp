//Zadanie 22. Stworz kalkulator dat. Czyli niech uzytkownik wprowadza najpierw jedna i druga date. Nastepnie niech wybiera co z ta data
//chce zrobic. Dostepne beda dzialania: dodawanie, odejmowanie, roznica dat, zmiana jednej z dat(dnia/miesiaca/roku).
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using year = duration<int, ratio<31556952>>;
using month = duration<int64_t, ratio<2629746>>;
using day = duration<int, ratio<3600 * 24>>;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Kalkulator_Dat{
    public:

    Kalkulator_Dat()
    {
        while(!wprowadzenie_danych());
    }

    void wlacz()
    {
        while (!operacje(pobierz_wprowadzenie()));
    }

    private:

    void wypisz_daty()
    {
        time_t t1 = system_clock::to_time_t(tp1);
        time_t t2 = system_clock::to_time_t(tp2);

        string t1_str = ctime(&t1); 
        t1_str.pop_back();
        string t2_str = ctime(&t2);
        t2_str.pop_back();

        cout << "Pierwsza data: " << t1_str << ", druga data: " << t2_str << endl;
    }

    ////////////////////////////////////////////////////////////

    void wypisz_operacje()
    {
        cout << "Dostepne operacje: \'+\' - dodawanie, \'-\' odejmowanie, \'R\' - roznica, \'q\' - wyjscie, 'r' - powtorz wprowadzenie"
        << ", 'm' - modyfikuj" << endl;
    }

    ////////////////////////////////////////////////////////////

    system_clock::time_point stworzTimePoint(int rok, int miesiac, int dzien) {
        struct std::tm t;
        t.tm_sec = 0;
        t.tm_min = 0;
        t.tm_hour = 0;
        t.tm_mday = dzien;
        t.tm_mon = miesiac - 1;
        t.tm_year = rok - 1900;
        t.tm_isdst = -1;
        time_t tt = mktime(&t);
        if(tt == -1) {
            throw exception();
        }
        return system_clock::from_time_t(tt);
    }

    ////////////////////////////////////////////////////////////

    bool wprowadzenie_danych(int ktore = 0) {
        int dzien = 1;
        int miesiac = 1;
        int rok = 1;

        bool czy_dobrze = false;

        if(ktore == 0 || ktore == 1)
        {
            cout << "Data pierwsza." << endl;

            while (!czy_dobrze)
            {
                cout << "Dzien : ";
                cin >> dzien;
                cout << "Miesiac:";
                cin >> miesiac;
                cout << "Rok:";
                cin >> rok;

                try
                {
                    tp1 = stworzTimePoint(rok, miesiac, dzien);
                    czy_dobrze = true;
                }
                catch (const std::exception &e)
                {
                    cout << "Niedozwolona data. Prosze powtorzyc!" << endl;
                }
            }
            czy_dobrze = false;
        }

        if(ktore == 0 || ktore == 2) {
            cout << "Data druga." << endl;

            while (!czy_dobrze)
            {
                cout << "Dzien : ";
                cin >> dzien;
                cout << "Miesiac:";
                cin >> miesiac;
                cout << "Rok:";
                cin >> rok;

                try
                {
                    tp2 = stworzTimePoint(rok, miesiac, dzien);
                    czy_dobrze = true;
                }
                catch (const std::exception &e)
                {
                    cout << "Niedozwolona data. Prosze powtorzyc!" << endl;
                }
            }
        }

        
        return true;
    }

    ////////////////////////////////////////////////////////////

    char pobierz_wprowadzenie() {
        wypisz_daty();
        wypisz_operacje();

        char znak;
        cin >> znak;
        return znak;
    }

    ////////////////////////////////////////////////////////////

    bool operacje(char znak) {
        switch (znak)
        {
        case '+':
            dodawanie();
            break;
        case '-':
            odejmowanie();
            break;
        case 'R':
            roznica();
            break;
        case 'q':
            return true;
            break;
        case 'r':
            while (!wprowadzenie_danych());
            break;
        case 'm':
            modyfikuj_date();
            break;

            default:
            cout << "Niezdefiniowany symbol!" << znak << endl;
            return false;
            break;
        }
        return false;
    }

    ////////////////////////////////////////////////////////////

    void dodawanie() {
        time_t t1 = system_clock::to_time_t(tp1);
        time_t t2 = system_clock::to_time_t(tp2);

        tm *wsk_kal_t1 = gmtime(&t1);
        tm *wsk_kal_t2 = gmtime(&t2);

        struct tm t;
        t.tm_sec = 0;
        t.tm_min = 0;
        t.tm_hour = 0;
        t.tm_mday = wsk_kal_t1->tm_mday + wsk_kal_t2->tm_mday;
        t.tm_mon = wsk_kal_t1->tm_mon + wsk_kal_t2->tm_mon;
        t.tm_year = wsk_kal_t1->tm_year + 1900 + wsk_kal_t2->tm_year + 1900 - 1900;
        t.tm_isdst = -1;
        time_t tt = mktime(&t);
        if (tt == -1)
        {
            cout << "Exception? Hmmm..." << endl;
            throw exception();
        }

        cout << "Otrzymana data: " << ctime(&tt) << endl;
    }

    ////////////////////////////////////////////////////////////

    void odejmowanie() {
        time_t t1 = system_clock::to_time_t(tp1);
        time_t t2 = system_clock::to_time_t(tp2);

        tm *wsk_kal_t1 = gmtime(&t1);
        tm *wsk_kal_t2 = gmtime(&t2);

        struct tm t;
        t.tm_sec = 0;
        t.tm_min = 0;
        t.tm_hour = 0;
        t.tm_mday = wsk_kal_t1->tm_mday - wsk_kal_t2->tm_mday;
        t.tm_mon = wsk_kal_t1->tm_mon - wsk_kal_t2->tm_mon;
        //t.tm_year = wsk_kal_t1->tm_year + 1900 - wsk_kal_t2->tm_year + 1900 - 1900;
        t.tm_isdst = -1;
        time_t tt = mktime(&t);
        if (tt == -1)
        {
            cout << "Exception? Hmmm..." << endl;
            throw exception();
        }

        string data_str = ctime(&tt);
        data_str = data_str.substr(0, data_str.find_last_of(':') + 2) + " " + to_string(wsk_kal_t1->tm_year - wsk_kal_t2->tm_year) + '\n';

        cout << "Otrzymana data: " << data_str << endl;
    }

    ////////////////////////////////////////////////////////////

    void roznica() {
        duration<int64_t, nano> okres;
        if(tp1 > tp2)
            okres = tp1.time_since_epoch() - tp2.time_since_epoch();
        else
            okres = tp2.time_since_epoch() - tp1.time_since_epoch();

        cout << "Roznica:\n\tLata: " << duration_cast<year>(okres).count() << "\n\tMiesiace: " << duration_cast<month>(okres % year(1)).count()
             << "\n\tDni: " << duration_cast<day>(okres % month(1)).count() << endl;
    }

    ////////////////////////////////////////////////////////////

    void modyfikuj_date()
    {
        bool wprowadzenie = true;
        int numer;
        while (wprowadzenie)
        {
            cout << "Data pierwsza - '1' / Data druga - '2' / Wyjsc - '3'" << endl;
            cin >> numer;
            if (numer == 1 || numer == 2 || numer == 3)
            {
                wprowadzenie = false;
            }
            else
            {
                cout << "Powtorz ponownie lub wyjdz wpisujac '3'" << endl;
            }
        }

        if(numer == 3) {
            return;
        }

        switch (numer)
        {
        case 1:
            while(!wprowadzenie_danych(1));
            break;
        case 2:
            while (!wprowadzenie_danych(2));
            break;

        default:
            break;
        }

    }



    ////////////////////////////////////////////////////////////

    system_clock::time_point tp1;
    system_clock::time_point tp2;
};
//*********************************************************************************************************************
int main()
{
        Kalkulator_Dat kalkulator;
        kalkulator.wlacz();
}