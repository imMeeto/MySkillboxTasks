#include <iostream> 

int main()
{
    std::string userName;
    std::cout << "Введите логин: ";
    std::cin  >> userName;

    std::string userPass;
    std::cout << "Введите пароль: ";
    std::cin  >> userPass;
    std::cout << "-----------------------" << "\n";

    std::cout << userName << ", вы успешно вошли!";
}