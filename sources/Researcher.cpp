#include "Researcher.hpp"
#include "City.hpp"
using namespace std;

namespace pandemic
{
    Researcher &Researcher::discover_cure(Color color)
    {
        const int min = 5;
        if (_cards.size() < min)
        {
            throw string("You must have 5 cards in the same color as the disease");
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
                if (count == min)
                {
                    break;
                }
            }
            if (count != min)
            {
                throw string("You must have 5 cards in the same color as the disease");
            }
            for (City c : matching_color_cities)
            {
                _cards.erase(c);
            }
            _board.cures.insert(color);
        }
        return *this;
    }
    string Researcher::role()
    {
        string ans = "Researcher";
        return ans;
    }
}