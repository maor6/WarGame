#include "Board.hpp"


namespace WarGame {

Soldier*& Board::operator[](std::pair<int,int> location){
    // if(location.first >= board.size() || location.first < 0 || 
    //     location.second >= board[location.first].size() || location.second < 0){
    //         throw std::runtime_error("outsid the board");
    // }
    // else if(board[location.first][location.second] != nullptr){
    //     throw std::runtime_error("there is a Soldier allready");
    // }
    return this->board[location.first][location.second];
}

 Soldier* Board::operator[](std::pair<int,int> location) const{
     std::cout << "const" << std::endl;
    if(location.first >= board.size() || location.first < 0 || 
        location.second >= board[location.first].size() || location.second < 0){
            throw std::runtime_error("outsid the board");
    }
    return this->board[location.first][location.second];
}
    
void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
    if (source.first < this->board.size() && source.second < this->board[0].size()){
        Soldier* s = this->board[source.first][source.second];
        if(s != nullptr && s->_player == player_number ){
            std::pair<int,int> p = checkMove(source, direction);
            this->board[p.first][p.second] = s;
            this->board[source.first][source.second] = nullptr;
            s->activity(this->board, p);
        }
        else throw std::runtime_error("invalid move");
    }
    else throw std::runtime_error("invalid move");
}

bool Board::has_soldiers(uint player_number) const{ // remember to change
    // std::vector<std::vector<Soldier*>>::iterator it;
    // std::vector<Soldier*>::iterator i;
    for(int i = 0; i < this->board.size() ; i++){
        for (int j = 0 ; j < this->board[i].size() ; j++){
            if(this->board[i][j] != nullptr){
                if(this->board[i][j]->_player == player_number){
                    return true;
                }
            }
        }
    }
    return false;
}


std::pair<int,int> Board::checkMove(std::pair<int,int> source, MoveDIR direction){
    if(direction == Up){
        if(source.first+1 < this->board.size() && 
            this->board[source.first+1][source.second] == nullptr){
                return {source.first+1, source.second};
        }
        throw std::runtime_error("invalid move");
    }
    else if(direction == Down){
        if(source.first-1 >= 0 && 
            this->board[source.first-1][source.second] == nullptr){
                return {source.first-1, source.second};
        }
        throw std::runtime_error("invalid move");
    }

    else if(direction == Right){
        if(source.second+1 < this->board[source.first].size() && 
            this->board[source.first][source.second+1] == nullptr){
                return {source.first, source.second+1};
        }
        throw std::runtime_error("invalid move");
    }

    else{
        if(source.second-1 >= 0 && 
            this->board[source.first][source.second-1] == nullptr){
                return {source.first, source.second-1};
        }
        throw std::runtime_error("invalid move");
    }
}

}