#ifndef _FOOTSOLDIER_H_
#define _FOOTSOLDIER_H_

#include "Soldier.hpp"




class FootSoldier: public Soldier{
    public:
    FootSoldier(int player):Soldier(player){
        _points = 100;
        _ability = 10;
        MAX_LIFE = 100;
        _type = "FootSoldier";
    }
    virtual void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override;

};

#endif
