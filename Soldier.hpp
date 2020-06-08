#ifndef _SOLDIER_H_
#define _SOLDIER_H_
#include <iostream>
#include <cmath>
#include <algorithm> 
#include <vector>


class Soldier{

    public:
        int _player;
        int _points;
        int _ability;
        int MAX_LIFE;
        std::string _type;
        

    Soldier(int player):_player(player){};

    virtual ~Soldier() {};

    virtual void activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) =0;

};




#endif