#include <string>
#include <cmath>
#include <vector>
using namespace std;

#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;

namespace pandemic
{
    Player &Player::drive(City city_drive)
    {
        if(_city==city_drive){
            throw string("Can't drive from city to itslef");
        }
        unordered_set<City> city_nei = Board::connections.find(_city)->second;
        if (city_nei.find(city_drive) == city_nei.end())
        {
            throw string("Can't drive to a non-connected city");
        }
        _city = city_drive;
        return *this;
    }
    Player &Player::fly_direct(City city_fd)
    {
        if(_city==city_fd){
            throw string("Can't fly from city to itslef");
        }
        if (_cards.find(city_fd) == _cards.end())
        {
            throw string("Missing city card in order to fly_direct");
        }
        _cards.erase(city_fd);
        _city = city_fd;
        return *this;
    }
    Player &Player::fly_shuttle(City city_fs)
    {
        if(_city==city_fs){
            throw string("Can't fly from city to itslef");
        }
        if (_board.stations.find(_city) == _board.stations.end())
        {
            throw string("Can fly_shuttle only from cities with reserach stations");
        }
        if (_board.stations.find(city_fs) == _board.stations.end())
        {
            throw string("Can fly_shuttle only to cities with reserach stations");
        }
        _city = city_fs;
        return *this;
    }
    Player &Player::fly_charter(City city_fc)
    {
        if(_city==city_fc){
            throw string("Can't fly from city to itslef");
        }
        if (_cards.find(_city) == _cards.end())
        {
            throw string("Missing your current city card in order to fly_charter");
        }
        _city = city_fc;
        return *this;
    }
    Player &Player::build()
    {
        if (_cards.find(_city) == _cards.end())
        {
            throw string("Missing your current city card in order to build");
        }
        if (_board.stations.find(_city) == _board.stations.end())
        {
            _board.stations.insert(_city);
            _cards.erase(_city);
        }
        return *this;
    }
    Player &Player::discover_cure(Color color)
    {
        
        if (_board.stations.find(_city) == _board.stations.end())
        {
            throw string("Can't find cure in a city with no research station");
        }
        const int min =5;
        if (_cards.size() < min)
        {
            throw string("You must have 5 cards in the same color as the disease");
        }
        if (_board.cures.find(color) == _board.cures.end())
        {
            unordered_set<City> matching_color_cities;
            int count = 0;
            for (City c : _cards)
            {
                if (Board::colors.find(c)->second == color)
                {
                    matching_color_cities.insert(c);
                    count++;
                }
                if (count == min)
                {
                    break;
                }
            }
            if (count != min)
            {
                throw string("You must have 5 cards in the same color as the disease");
            }
            for (City c : matching_color_cities)
            {
                _cards.erase(c);
            }
            _board.cures.insert(color);
        }
        return *this;
    }
    Player &Player::treat(City city)
    {
        if(_board.diseases.find(_city) == _board.diseases.end() || _board.diseases.find(_city)->second == 0){
            throw string("There is no disease in the current city");
        }
        _board[_city] = _board.cures.find(Board::colors.find(_city)->second)==_board.cures.end()? _board[_city]-1 : 0;
        return *this;
    }
    string Player::role()
    {
        string ans = "Player";
        return ans;
    }
    Player &Player::take_card(City city)
    {
        if (_cards.find(city) == _cards.end())
        {
            _cards.insert(city);
        }
        return *this;
    }
    Player &Player::remove_cards()
    {
        _cards.clear();
        return *this;
    }

}