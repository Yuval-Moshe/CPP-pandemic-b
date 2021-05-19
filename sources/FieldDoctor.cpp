#include "FieldDoctor.hpp"
#include "City.hpp"
using namespace std;

namespace pandemic
{
    FieldDoctor& FieldDoctor::treat(City city){
        if(_city == city){
            try{
                Player::treat(city);
                return *this;
            }
            catch (string e){
                throw e;
            }
        }
        unordered_set<City> city_nei = Board::connections.find(_city)->second;
        if (city_nei.find(city) == city_nei.end())
        {
            throw string("Can't treat to a non-connected city");
        }
        if(_board.diseases.find(city) == _board.diseases.end() || _board.diseases.find(city)->second == 0){
            throw string("There is no disease in the wanted city");
        }
        _board[city] = _board.cures.find(Board::colors.find(city)->second)==_board.cures.end()? _board[city]-1 : 0;
        return *this;
    }
    string FieldDoctor::role()
    {
        string ans = "FieldDoctor";
        return ans;
    }

}