#include <iostream> 

int main()
{
int shiftTime = 480;
int orderTime = 4;
int orderExecutionTime = 9;
int serviceTime = orderTime + orderExecutionTime;
int ordersPerShift = shiftTime / serviceTime;

    std::cout << "-----------------------------------------------------------------------------" << "\n";
    std::cout << "Эта программа рассчитает, сколько клиентов ресторана «Крылышки и ножки»" << "\n";
    std::cout << "успеет обслужить кассир за смену." << "\n";
    std::cout << "-----------------------------------------------------------------------------" << "\n";
    std::cout << "Какая продолжительность смены? " << shiftTime << " минут." << "\n";
    std::cout << "Сколько клиент делает заказ? " << orderTime << " минуты." << "\n";
    std::cout << "Сколько кассир собирает заказ? " << orderExecutionTime << " минут." << "\n";
    std::cout << "Расчитываем..." << "\n";
    std::cout << "-----------------------------------------------------------------------------" << "\n";
    std::cout << "За смену длиной " << shiftTime << " минут кассир успеет обслужить " << ordersPerShift << " клиентов." << "\n";
    std::cout << "-----------------------------------------------------------------------------" << "\n"; 
}