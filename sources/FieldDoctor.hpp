#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        FieldDoctor(Board &board, City city):Player(board,city){};
        FieldDoctor &treat(City city);
        string role();
    };
}