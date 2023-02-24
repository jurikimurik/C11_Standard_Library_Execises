#include <vector>
#include "dice.h"
#include "player.h"
//************************************************************************************************************************
class GameManager
{
    private:
        std::vector<Player> gracze;

    public:

    void rozpocznij_gre()
    {
        //Niech zyje losowosc!
        srand(time(NULL));
    }
};