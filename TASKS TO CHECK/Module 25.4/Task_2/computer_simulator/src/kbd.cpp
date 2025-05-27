#include "ram.h"
#include <iostream>

void input()
{
    int buffer[8];
    std::cout << "Enter 8 numbers: ";
    
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> buffer[i];
    }
    
    write(buffer);
}