/*5. Udoskonalic skrypt printtuple.hpp (podany)*/

#include <tuple>
#include <iostream>
using namespace std;

#define CZY_STARA_METODA false
#if CZY_STARA_METODA == true

template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE
{
    static void print (std::ostream& strm, const std::tuple<Args...>& t) {
        strm << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ", ");
        PRINT_TUPLE<IDX + 1, MAX, Args...>::print(strm, t);
    }
};

template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
    static void print (std::ostream& strm, const std::tuple<Args... >& t) {}
};

template <typename... Args>
std::ostream& operator<< (std::ostream& strm, const std::tuple<Args...>&t) {
    strm << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
    return strm << "]";
}

#else

template <typename... Args>
std::ostream &operator<<(std::ostream &strm, const std::tuple<Args...> &t)
{
    strm << "[";
    for (constexpr int i = 0, MAX = sizeof...(Args); i < MAX; i++)
    {
        strm << get<i>(t) << ", ";
    }
        return strm << "]";
}

#endif

int main()
{
    tuple<int, float, string> t(77, 1.1, "wiecej pary");
    cout << "io: " << t << endl;
}