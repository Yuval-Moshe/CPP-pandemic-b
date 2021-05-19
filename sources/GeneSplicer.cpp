#include "GeneSplicer.hpp"
#include "City.hpp"
using namespace std;

namespace pandemic
{
    GeneSplicer& GeneSplicer::discover_cure(Color color){
        if (_board.stations.find(_city) == _board.stations.end())
        {
            throw string("Can't find cure in a city with no research station");
        }
        const int min = 5;
        if (_cards.size() < min)
        {
            throw string("You must have 5 cards in the same color as the disease");
        }
        if (_board.cures.find(color) == _board.cures.end())
        {
            for (City c : _cards)
            {
                _cards.erase(c);
            }
            _board.cures.insert(color);
        }
        return *this;
    }
    string GeneSplicer::role()
    {
        string ans = "GeneSplicer";
        return ans;
    }
}