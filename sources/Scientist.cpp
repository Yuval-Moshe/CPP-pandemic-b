#include "Scientist.hpp"
#include "City.hpp"
using namespace std;

namespace pandemic
{
    Scientist &Scientist::discover_cure(Color color)
    {
        if (_board.stations.find(_city) == _board.stations.end())
        {
            throw string("Can't find cure in a city with no research station");
        }
        if (_cards.size() < n)
        {
            throw string("You must have"+to_string(n)+" cards in the same color as the disease");
        }
        if (_board.cures.find(color) == _board.cures.end())
        {
            unordered_set<City> matching_color_cities;
            int count = 0;
            for (City c : _cards)
            {
                if (Board::colors.find(c)->second == color)
                {
                    matching_color_cities.insert(c);
                    count++;
                }
                if (count == n)
                {
                    break;
                }
            }
            if (count != n)
            {
                throw string("You must have"+to_string(n)+" cards in the same color as the disease");
            }
            for (City c : matching_color_cities)
            {
                _cards.erase(c);
            }
            _board.cures.insert(color);
        }
        return *this;
    }
    string Scientist::role()
    {
        string ans = "Scientist";
        return ans;
    }
}