#include <iostream> 

int main()
{
    std::cout << "--------------------------" << "\n";
    std::cout << "Вычесление квадрата числа." << "\n";
    std::cout << "--------------------------" << "\n"; 
    std::cout << "Введите число: ";
    int a;
    std::cin  >> a;
    std::cout << "Вы ввели: " << a << "\n";;
    std::cout << "----------" << "\n";
    std::cout << "Рассчитываем..." << "\n";
    int squareNumber = a * a;
    std::cout << "--------------------------" << "\n";
    std::cout << "Число " << a << " в квадрате = " << squareNumber << "\n";
    std::cout << "--------------------------" << "\n"; 
}