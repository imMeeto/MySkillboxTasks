#include <iostream>
#include <vector>

enum RoomType {BEDROOM, KITCHEN, BATHROOM, CHILDREN, LIVING};
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
  std::cout << "Number of rooms (2-4): ";
  std::cin >> roomCount;

  for (int i = 0; i < roomCount; ++i)
  {
    std::cout << " - Room " << i + 1 << ":\n";
    floor.rooms.push_back(inputRoom());
  }
  
  return floor;
}

House inputHouse()
{
  House house;

  int floorCount;
  std::cout << "Number of floors (1-3): ";
  std::cin >> floorCount;
  
  for (int i = 0; i < floorCount; ++i)
  {
    std::cout << "- Floor " << i + 1 << ":\n";
    house.floors.push_back(inputFloor());

  }
  
  char stove;
  std::cout << "Is there a stove? (y/n): ";
  std::cin >> stove; 
  house.hasStove = (stove == 'y' || stove == 'Y'); // преобразуем ответ в true/false

  return house;
}

Bathhouse inputBathhouse()
{
  Bathhouse bathhouse;

  std::cout << "Bathhouse area: ";
  std::cin >> bathhouse.area;

  char stove;
  std::cout << "Is there a stove? (y/n): ";
  std::cin >> stove; 
  bathhouse.hasStove = (stove == 'y' || stove == 'Y');

  return bathhouse;
}

Barn inputBarn()
{
  Barn barn;
  std::cout << "Barn area: ";
  std::cin >> barn.area;
  return barn;
}

Garage inputGarage()
{
  Garage garage;
  std::cout << "Garage area: ";
  std::cin >> garage.area;
  return garage;
}

Plot inputPlot(int plotNumber)
{
  Plot plot;
  plot.plotNumber = plotNumber;

  std::cout << "Total plot area: ";
  std::cin >> plot.totalPlotArea;

  int buildingCount;
  std::cout << "Number of buildings: ";
  std::cin >> buildingCount;

  for (int i = 0; i < buildingCount; ++i)
  {
    int buildingType;
    std::cout << "Type of building (0-house, 1-bathhouse, 2-barn, 3-garage): ";
    std::cin >> buildingType;

    if (buildingType == HOUSE)
    {
      plot.houses.push_back(inputHouse());
    }
    else if (buildingType == BATHHOUSE)
    {
      plot.bathhouses.push_back(inputBathhouse());
    }
    else if (buildingType == BARN)
    {
      plot.barns.push_back(inputBarn());
    }
    else if (buildingType == GARAGE)
    {
      plot.garages.push_back(inputGarage());
    }
    else
    {
      std::cout << "Error: Unknown type of building!\n";
    }
  }
  
  return plot;
}

float calculateOccupiedArea(Plot& plot)
{
  float occupied = 0.0f;

  for (int i = 0; i < plot.houses.size(); ++i) //для каждого дома
  {
    for (int j = 0; j < plot.houses[i].floors.size(); ++j) //для каждого этажа
    {
      for (int k = 0; k < plot.houses[i].floors[j].rooms.size(); ++k) //для каждой комнаты
      {
        occupied += plot.houses[i].floors[j].rooms[k].area; //cуммируем площади
      }
    }
  }
  
  for (int i = 0; i < plot.bathhouses.size(); ++i)
  {
    occupied += plot.bathhouses[i].area;
  }

  for (int i = 0; i < plot.barns.size(); ++i)
  {
    occupied += plot.barns[i].area;
  }
  
  for (int i = 0; i < plot.garages.size(); ++i)
  {
    occupied += plot.garages[i].area;
  }
  
  return occupied;
}

int main()  
{
  std::cout << "***The data model for the village.***\n\n";
  int plotCount;

  std::cout << "Input number of plots: ";
  std::cin >> plotCount;

  std::vector<Plot> village;

  for (int i = 0; i < plotCount; ++i)
  {
    village.push_back(inputPlot(i + 1));
  }
  
  for (int i = 0; i < village.size(); ++i)
  {
    float occupied = calculateOccupiedArea(village[i]);   //расчёт занятой площади

    float percentage = (occupied / village[i].totalPlotArea) * 100; //расчет процента
    
    std::cout << "\n-----------------------------\n";
    std::cout << "- Plot " << village[i].plotNumber << ": " 
              << occupied << " sq.m occupied (" 
              << percentage << "% of the total area)\n";
  }

  return 0;
}