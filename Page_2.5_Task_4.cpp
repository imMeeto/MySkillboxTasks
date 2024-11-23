#include <iostream> 

int main()
{
int receiptPrice = 4000000;
int entrance = 10;
int apartamentsInEntrance = 40;
int allApartaments = apartamentsInEntrance * entrance;
int receiptPriceForApartament = receiptPrice / allApartaments;

    std::cout << "-----------------------------------------------" << "\n";
    std::cout << "Приветствуем вас в калькуляторе квартплаты!" << "\n";
    std::cout << "-----------------------------------------------" << "\n";
    std::cout << "Введите сумму, указанную в квитанции: " << receiptPrice << "\n";
    std::cout << "Сколько подъездов в вашем доме? " << entrance << "\n";
    std::cout << "Сколько квартир в каждом подъезде? " << apartamentsInEntrance << "\n";
    std::cout << "Расчитываем..." << "\n";
    std::cout << "-----------------------------------------------" << "\n";
    std::cout << "Каждая квартира должна платить по " << receiptPriceForApartament << " рублей." << "\n";
    std::cout << "-----------------------------------------------" << "\n"; 
}