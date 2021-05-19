#include "Medic.hpp"
#include "City.hpp"
using namespace std;

namespace pandemic
{
    Medic &Medic::drive(City city_drive)
    {
        try
        {
            Player::drive(city_drive);
            if (_board.cures.find(Board::colors.find(_city)->second) != _board.cures.end())
            {
                _board[_city] = 0;
            }
            return *this;
        }
        catch (string e)
        {
            throw e;
        }
    }
    Medic &Medic::fly_direct(City city_fd)
    {
        try
        {
            Player::fly_direct(city_fd);
            if (_board.cures.find(Board::colors.find(_city)->second) != _board.cures.end())
            {
                _board[_city] = 0;
            }
            return *this;
        }
        catch (string e)
        {
            throw e;
        }
    }
    Medic &Medic::fly_shuttle(City city_fs)
    {
        try
        {
            Player::fly_shuttle(city_fs);
            if (_board.cures.find(Board::colors.find(_city)->second) != _board.cures.end())
            {
                _board[_city] = 0;
            }
            return *this;
        }
        catch (string e)
        {
            throw e;
        }
    }
    Medic &Medic::fly_charter(City city_fc)
    {
        try
        {
            Player::fly_charter(city_fc);
            if (_board.cures.find(Board::colors.find(_city)->second) != _board.cures.end())
            {
                _board[_city] = 0;
            }
            return *this;
        }
        catch (string e)
        {
            throw e;
        }
    }
    Medic &Medic::treat(City city)
    {
        if(_board.diseases.find(_city) == _board.diseases.end() || _board.diseases.find(_city)->second == 0){
            throw string("There is no disease in the current city");
        }
        _board[_city] = 0;
        return *this;
    }
    string Medic::role()
    {
        string ans = "Medic";
        return ans;
    }
}