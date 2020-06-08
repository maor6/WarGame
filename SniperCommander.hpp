#ifndef _SNIPERCOMMANDER_H_
#define _SNIPERCOMMANDER_H_


#include "Sniper.hpp"



class SniperCommander : public Sniper{
    public:
    SniperCommander(int player): Sniper(player){
        _points = 120;
        _ability = 100;
        MAX_LIFE = 120;
        _type = "SniperCommander";
    }
    virtual void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override;

};

#endif

