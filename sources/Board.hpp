#pragma once

#include <ostream>
#include <iostream> //remove    
#include <ios> // remove
#include <unordered_map>
#include <unordered_set>
using namespace std;

#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;

namespace pandemic
{
    class Board
    {
        friend ostream &operator<<(ostream &output, Board &board);
    public:
        static bool initialized;
        static unordered_map<City, unordered_set<City>> connections;
        static unordered_map<City, Color> colors;
        unordered_map<City, int> diseases = {};
        unordered_set<Color> cures = {};
        unordered_set<City> stations = {};

        Board(){
            if(!Board::initialized){
                Board::initilize();
            }
        }
        static void initilize(); 
        int &operator[](City city);
        bool is_clean();
        Board &remove_cures();
    };
}