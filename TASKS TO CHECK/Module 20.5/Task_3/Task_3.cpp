#include <iostream>
#include <fstream>
#include <string>

int countFishInRiver(const std::string& filePath, const std::string& fishType)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error opening river file.\n";
        return -1;
    }
    
    int count = 0;
    std::string line;
    while (std::getline(file, line))
    {
        if (line == fishType) count++;
    }
    return count;
}

void addFishToBasket(const std::string& filePath, const std::string& fishType, int catchCount)
{
    std::ofstream file(filePath, std::ios::app);
    if (!file.is_open())
    {
        std::cerr << "Error opening basket file.\n";
        return;
    }

    for (int i = 0; i < catchCount; i++)
    {
        file << fishType << std::endl;
    }
    
    std::cout << "\nGood! Added " << catchCount << " " << fishType << " to the basket!\n";
}

int main()
{
    std::cout << "*** Fishing simulator ***\n";
    std::cout << "To get started: \n";

    std::cout << "1) Input the full path to the river file: \n";
    std::string riverPath;
    std::getline(std::cin, riverPath);
    
    std::cout << "2) Input the full path to the basket file: \n";
    std::string basketPath;
    std::getline(std::cin, basketPath);
    
    std::cout << "\nWhat kind of fish are you going to catch?\n";
    std::cout << "- Input type of fish: ";
    std::string fishType;
    std::getline(std::cin, fishType);
    
    int caughtCount = countFishInRiver(riverPath, fishType);
    if (caughtCount > 0)
    {
        addFishToBasket(basketPath, fishType, caughtCount);
        std::cout << "Total number of fish caught: " << caughtCount << std::endl;
    }
    else
    {
        std::cout << "No " << fishType << " found in the river.\n";
    }
    
    return 0;
}
