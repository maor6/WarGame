#include "Paramedic.hpp"


void Paramedic::activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location){
    for(int i = location.first-1;i <= location.first+1 && i != board.size(); i++){ // serch the nearest soldier to attack
        for (int j = location.second-1;j <= location.second+1 && j < board[i].size() ; j++){
            if (board[i][j] != nullptr && 
            board[i][j]->_player == board[location.first][location.second]->_player &&
            (i != location.first || j != location.second)){
                board[i][j]->_points = std::min(board[i][j]->MAX_LIFE,board[i][j]->_points + this->_ability);
            }
        }
    }
}