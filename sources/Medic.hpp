#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board &board, City city):Player(board,city){};
        Medic &drive(City city_drive);
        Medic &fly_direct(City city_fd);
        Medic &fly_shuttle(City city_fs);
        Medic &fly_charter(City city_fc);
        Medic &treat(City city);
        string role();
    };
}