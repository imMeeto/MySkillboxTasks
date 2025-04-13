#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

const int SECTORS_COUNT = 13;
const int WIN_SCORE = 6;

struct Sector {
    int sectorNumber;
    bool isSectorPlayed; 
    std::string question;
    std::string answer;
};

std::vector<std::string> readAllLines(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    
    return lines;
}

int main()
{

}