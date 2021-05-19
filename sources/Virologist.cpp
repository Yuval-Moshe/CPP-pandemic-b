#include "Virologist.hpp"
#include "City.hpp"
using namespace std;

namespace pandemic
{
    Virologist &Virologist::treat(City city){
        if(_city == city){
            try{
                Player::treat(city);
                return *this;
            }
            catch (string e){
                throw e;
            }
        }
        else if(_board.diseases.find(city) == _board.diseases.end() || _board.diseases.find(city)->second == 0){
            throw string("There is no disease in the current city");
        }
        else if(_cards.find(city)==_cards.end()){
            throw string("Missing city card to preform long distance cure");
        }
        _board[city] = _board.cures.find(Board::colors.find(city)->second)==_board.cures.end()? _board[city]-1 : 0;
        return *this;
    }
    string Virologist::role()
    {
        string ans = "Virologist";
        return ans;
    }
}