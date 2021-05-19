#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
    class Scientist : public Player
    {
    public:
        int n;
        Scientist(Board &n_board, City n_city, int n_n):Player(n_board,n_city), n(n_n){};
        Scientist& discover_cure(Color color);
        string role();
    };
}