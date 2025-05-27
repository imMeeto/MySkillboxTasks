#include "ram.h"
#include <fstream>

void save()
{
    int buffer[8];
    read(buffer);
    
    std::ofstream file("data.txt");
    for (int i = 0; i < 8; ++i)
    {
        file << buffer[i] << " ";
    }
}

void load()
{
    int buffer[8];
    std::ifstream file("data.txt");
    
    for (int i = 0; i < 8; ++i)
    {
        file >> buffer[i];
    }
    
    write(buffer);
}