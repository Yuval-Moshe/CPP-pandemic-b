#include <string>
#include <cmath>
#include <vector>
using namespace std;

#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;

namespace pandemic{

    OperationsExpert &OperationsExpert::build()
    {
        if (_board.stations.find(_city) == _board.stations.end())
        {
            _board.stations.insert(_city);
        }
        return *this;
    }
    string OperationsExpert::role()
    {
        string ans = "OperationsExpert";
        return ans;
    }

}