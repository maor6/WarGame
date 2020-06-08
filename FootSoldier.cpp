#include "FootSoldier.hpp"


void FootSoldier::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location){
    std::pair<int,int> ToAttack;
    long MinDistance = pow(board.size(),2);
    for(int i = 0; i != board.size() ; i++){ // serch the nearest soldier to attack
        for (int j = 0 ; j < board[i].size() ; j++){
            if(board[i][j] != nullptr &&
             board[i][j]->_player != board[location.first][location.second]->_player ){
                long CurrDis = sqrt(pow(i - location.first,2) + pow(j - location.second,2));
                if (CurrDis < MinDistance) {
                    MinDistance = CurrDis;
                    ToAttack = {i,j};
                } 

            }
        }
    }//need if not have enemy soldier
    if(MinDistance != pow(board.size(),2)){
        board[ToAttack.first][ToAttack.second]->_points -= board[location.first][location.second]->_ability;
        if (board[ToAttack.first][ToAttack.second]->_points <= 0){ //check if the soldier is dead
            board[ToAttack.first][ToAttack.second] = nullptr;
        }
    }
    
}