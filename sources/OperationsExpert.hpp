#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        OperationsExpert(Board &board, City city):Player(board,city){};
        OperationsExpert &build();
        string role();
    };
}