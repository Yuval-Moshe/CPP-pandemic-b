#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
    class Researcher : public Player
    {
    public:
        Researcher(Board &board, City city):Player(board,city){};
        Researcher &discover_cure(Color color);
        string role();
    };
}