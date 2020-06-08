#ifndef _SNIPER_H_
#define _SNIPER_H_
#include <limits>
#include "Soldier.hpp"


class Sniper : public Soldier{
    public:
    Sniper(int player): Soldier(player){
        _points = 100;
        _ability = 50;
        MAX_LIFE = 100;
        _type = "Sniper";
    }
    virtual void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override;
};

#endif

