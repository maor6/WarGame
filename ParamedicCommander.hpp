
#ifndef _PARAMEDICCOMMANDER_H_
#define _PARAMEDICCOMMANDER_H_


#include "Paramedic.hpp"



class ParamedicCommander : public Paramedic{
    public:
    ParamedicCommander(int player): Paramedic(player){
        _points = 200;
        _ability = 100;
        MAX_LIFE = 200;
        _type = "ParamedicCommander";
    }
    virtual void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location)override;

};

#endif