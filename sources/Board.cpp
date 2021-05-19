#include <ostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
using namespace std;

#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
     bool Board::initialized = false;
     unordered_map<City, unordered_set<City>> Board::connections ={};
     unordered_map<City, Color> Board::colors ={};
    int & Board::operator[](City city)
    {
        if (diseases.find(city) == diseases.end())
        {
            diseases.insert({city, 0});
        }
        return diseases.find(city)->second;
    }
    bool Board::is_clean() { 
        for(auto& it : diseases){
            if(it.second !=0){
                return false;
            }
        }
        return true;}
    ostream &operator<<(ostream &output, Board &board)
    {
        return output;
    }
    Board &Board::remove_cures()
    {
        cures.clear();
        return *this;
    };

    void Board::initilize()
    {
    unordered_map<string, City> str_enum_map_city; 
    unordered_map<string, Color> str_enum_map_color; 
    str_enum_map_city.insert({"Algiers", City::Algiers});
    str_enum_map_city.insert({"Atlanta", City::Atlanta});
    str_enum_map_city.insert({"Baghdad", City::Baghdad});
    str_enum_map_city.insert({"Bangkok", City::Bangkok});
    str_enum_map_city.insert({"Beijing", City::Beijing});
    str_enum_map_city.insert({"Bogota", City::Bogota});
    str_enum_map_city.insert({"BuenosAires", City::BuenosAires});
    str_enum_map_city.insert({"Cairo", City::Cairo});
    str_enum_map_city.insert({"Chennai", City::Chennai});
    str_enum_map_city.insert({"Chicago", City::Chicago});
    str_enum_map_city.insert({"Delhi", City::Delhi});
    str_enum_map_city.insert({"Essen", City::Essen});
    str_enum_map_city.insert({"HoChiMinhCity", City::HoChiMinhCity});
    str_enum_map_city.insert({"HongKong", City::HongKong});
    str_enum_map_city.insert({"Istanbul", City::Istanbul});
    str_enum_map_city.insert({"Jakarta", City::Jakarta});
    str_enum_map_city.insert({"Johannesburg", City::Johannesburg});
    str_enum_map_city.insert({"Karachi", City::Karachi});
    str_enum_map_city.insert({"Khartoum", City::Khartoum});
    str_enum_map_city.insert({"Kinshasa", City::Kinshasa});
    str_enum_map_city.insert({"Kolkata", City::Kolkata});
    str_enum_map_city.insert({"Lagos", City::Lagos});
    str_enum_map_city.insert({"Lima", City::Lima});
    str_enum_map_city.insert({"London", City::London});
    str_enum_map_city.insert({"LosAngeles", City::LosAngeles});
    str_enum_map_city.insert({"Madrid", City::Madrid});
    str_enum_map_city.insert({"Manila", City::Manila});
    str_enum_map_city.insert({"MexicoCity", City::MexicoCity});
    str_enum_map_city.insert({"Miami", City::Miami});
    str_enum_map_city.insert({"Milan", City::Milan});
    str_enum_map_city.insert({"Montreal", City::Montreal});
    str_enum_map_city.insert({"Moscow", City::Moscow});
    str_enum_map_city.insert({"Mumbai", City::Mumbai});
    str_enum_map_city.insert({"NewYork", City::NewYork});
    str_enum_map_city.insert({"Osaka", City::Osaka});
    str_enum_map_city.insert({"Paris", City::Paris});
    str_enum_map_city.insert({"Riyadh", City::Riyadh});
    str_enum_map_city.insert({"SanFrancisco", City::SanFrancisco});
    str_enum_map_city.insert({"Santiago", City::Santiago});
    str_enum_map_city.insert({"SaoPaulo", City::SaoPaulo});
    str_enum_map_city.insert({"Seoul", City::Seoul});
    str_enum_map_city.insert({"Shanghai", City::Shanghai});
    str_enum_map_city.insert({"StPetersburg", City::StPetersburg});
    str_enum_map_city.insert({"Sydney", City::Sydney});
    str_enum_map_city.insert({"Taipei", City::Taipei});
    str_enum_map_city.insert({"Tehran", City::Tehran});
    str_enum_map_city.insert({"Tokyo", City::Tokyo});
    str_enum_map_city.insert({"Washington", City::Washington});
    str_enum_map_color.insert({"Red", Color::Red});
    str_enum_map_color.insert({"Blue", Color::Blue});
    str_enum_map_color.insert({"Black", Color::Black});
    str_enum_map_color.insert({"Yellow", Color::Yellow});
    ifstream units_file{"cities_map.txt"};
    string line;
    while (getline(units_file, line))
    {
        int i = 0;
        istringstream is(line);
        string curr_city;
        for (string word; is >> word;)
        {
            if(i==0){
                curr_city = word;
                unordered_set<City> un;
                Board::connections.insert({str_enum_map_city.find(curr_city)->second, un});
            }
            else if (i==1){
                Board::colors.insert({str_enum_map_city.find(curr_city)->second, str_enum_map_color.find(word)->second});
            }
            else{
                Board::connections.find(str_enum_map_city.find(curr_city)->second)->second.insert(str_enum_map_city.find(word)->second);
            }
            i++;
        }
    }
    }

}