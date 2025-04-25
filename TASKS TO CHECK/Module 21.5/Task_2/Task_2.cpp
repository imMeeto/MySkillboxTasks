#include <iostream>
#include <vector>

enum RoomType {BEDROOM, KICHEN, BATHROOM, CHILDREN, LIVING};
enum BuildingType {HOUSE, BATHHOUSE, BARN, GARAGE};

struct Room 
{
  RoomType roomType;
  float area;
};

struct Floor
{
  float ceilingHeight;
  std::vector<Room> rooms;
};

struct House
{
  std::vector<Floor> floors;
  bool hasStove;
};

struct Bathhouse
{
  float area;
  bool hasStove;
};

struct Barn
{
  float area;
};

struct Garage
{
  float area;
};

struct Plot
{
  int plotNumber;
  float totalPlotArea;
  std::vector<House> houses;
  std::vector<Bathhouse> bathhouses;
  std::vector<Barn> barns;
  std::vector<Garage> garages;
};

int main()
{

}