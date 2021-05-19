#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic{
    class GeneSplicer: public Player{
        public:
            GeneSplicer(Board &board, City city):Player(board,city){};
            GeneSplicer &discover_cure(Color color);
            string role();

    };
}