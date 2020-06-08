#include "Sniper.hpp"


void Sniper::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location){
    std::pair<int,int> ToAttack;
    int Strongest =  -1;
    for(int i = 0; i < board.size() ; i++){ // serch the nearest soldier to attack
        for (int j = 0 ; j < board[i].size() ; j++){
            if(board[i][j] != nullptr &&
                 board[i][j]->_player != board[location.first][location.second]->_player ){
                long CurrStrong = board[i][j]->_points;
                if (CurrStrong > Strongest) {
                    Strongest = CurrStrong;
                    ToAttack = {i,j};
                } 

            }
        }
    }//need if not have enemy soldier
    if(Strongest != -1){
        board[ToAttack.first][ToAttack.second]->_points -= board[location.first][location.second]->_ability;
        if (board[ToAttack.first][ToAttack.second]->_points <= 0){ //check if the soldier is dead
            board[ToAttack.first][ToAttack.second] = nullptr;
        }
    }

}