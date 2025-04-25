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

Room inputRoom()
{
  Room room;
  int inputRoomType;

  std::cout << "Room type (0-bedroom, 1-kitchen, 2-bathroom, 3-children's room, 4-living room): ";
  std::cin >> inputRoomType;

  room.roomType = static_cast<RoomType>(inputRoomType); //преобразуем введенное число в тип RoomType

  std::cout << "Room area: ";
  std::cin >> room.area;

  return room;
}

Floor inputFloor()
{
  Floor floor;
  
  std::cout << "Ceiling height: ";
  std::cin >> floor.ceilingHeight;

  int roomCount;
  std::cout << "Number of rooms: ";
  std::cout << roomCount;

  for (int i = 0; i < roomCount; ++i)
  {
    std::cout << "Room " << i + 1 << ":\n";
    floor.rooms.push_back(inputRoom());
  }
  
}

int main()  
{

}