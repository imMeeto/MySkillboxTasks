#include <iostream>
#include <string>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"

int main()
{
    std::string command;
    
    while (true)
    {
        std::cout << "Enter command (sum/save/load/input/display/exit): ";
        std::cin >> command;
        
        if (command == "sum")
        {
            compute();
        }
        else if (command == "save")
        {
            save();
        }
        else if (command == "load")
        {
            load();
        }
        else if (command == "input")
        {
            input();
        }
        else if (command == "display")
        {
            display();
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    
    return 0;
}