#include <iostream> 

int main()
{
    std::string userName;
    std::cout << "Введите имя персонажа: ";
    std::cin  >> userName;
    std::cout << "-------------------------" << "\n"; 

    std::string characterRace;
    std::cout << "Введите расу персонажа: ";
    std::cin  >> characterRace;
    std::cout << "-------------------------" << "\n";
    
    std::cout << "Родился новый " << characterRace << ", его зовут " << userName << ".\n";
    std::cout << "Добро пожаловать в этот суровый мир!";
}