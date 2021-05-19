#include "Dispatcher.hpp"
#include "City.hpp"
using namespace std;

namespace pandemic
{
    Dispatcher &Dispatcher::fly_direct(City city_fd)
    {
        if (_city == city_fd)
        {
            throw string("Can't fly from city to itslef");
        }
        if (_board.stations.find(_city) != _board.stations.end())
        {
            _city = city_fd;
            return *this;
        }
        try
        {
            Player::fly_direct(city_fd);
            return *this;
        }
        catch (string e)
        {
            throw e;
        }
    }
    string Dispatcher::role()
    {
        string ans = "Dispatcher";
        return ans;
    }
}