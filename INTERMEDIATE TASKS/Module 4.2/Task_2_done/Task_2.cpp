#include <iostream>

int main() {
    std::cout << "---Рассчитайте, сумеете ли вы добраться на автомобиле из Москвы до Рязани за два часа с заданной средней скоростью.---" << "\n";
    std::cout << "Введите среднюю скорость в км/ч: ";
    int speed;
    std::cin >> speed; 

    int range = speed * 2;
    std::cout << "Со скоростью " << speed << " км/ч, за 2 часа вы проедете ";
    std::cout << range << " км." << "\n";

    if (range < 200)
    {
        std::cout << "От Рязани до москвы 200 килломметров, поэтому вы не сможете добраться с этой скоростью за 2 часа!";
    }
    
    if (range >= 200)
    {
        std::cout << "От Рязани до москвы 200 килломметров, поэтому вы сможете добраться с этой скоростью за 2 часа!" << "\n";
        std::cout << "---Едем---" << "\n";
        std::cout << "Поздравляю, вы приехали!"; 
    }
}