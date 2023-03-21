// Zadanie 12 - Zamaskowana zamiana. Niech użytkownik wpisze liczby. Następnie trzeba ich dodać do strumienia typu string w taki sposób, żeby były przekształcone w liczby szesnastkowe i zapisane do pliku. 
//Następnie niech drugi strumien odczyta te dane w sposób prawidłowy i wypisze te liczby w postaci dziesiętnej.
//Stringstream
//Istringstream
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../narzedzia.h"
using namespace std;

int main()
{
    vector<int> liczby = wprowadz_ciag<vector<int>>("Wprowdz liczby po czym wprowadz znak 'q':");

    ostringstream strm_str_out;

    strm_str_out << hex;
    for (const auto &elem : liczby)
    {
        strm_str_out << elem << " ";
    }

    ofstream strm_file_out("numbers.tmp");
    strm_file_out << strm_str_out.str();
    strm_file_out.close();

    ifstream strm_file_in("numbers.tmp");
    strm_file_in >> hex;
    while (true)
    {
        int liczba;
        strm_file_in >> liczba;
        if(!strm_file_in)
            break;
        else
            cout << liczba << " ";
    }
}
