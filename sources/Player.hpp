#pragma once
#include <string>
#include <unordered_set>
using namespace std;

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;

namespace pandemic
{
    class Player
    {
        friend Board;
    protected: 
        Board& _board;
        City _city; 
        unordered_set<City> _cards; 
    public:
        Player(Board& n_board, City n_city):_city(n_city), _board(n_board){
            _cards = {};
        }
        virtual Player &drive(City city_drive);
        virtual Player &fly_direct(City city_fd);
        virtual Player &fly_shuttle(City city_fs);
        virtual Player &fly_charter(City city_fc);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City city);
        virtual string role();
        virtual Player &take_card(City city);
        virtual Player &remove_cards();
    };
}