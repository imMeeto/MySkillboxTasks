#include <iostream> 

int main()
{
int tshirtPrice = 1480;
int deliveryPrice = 550;
int discount = 115;
int fullPrice = tshirtPrice + deliveryPrice - discount;

    std::cout << "Стоимость футболки: " << tshirtPrice << " рублей." << "\n";
    std::cout << "Стоимость доставки: " << deliveryPrice << " рублей." << "\n";
    std::cout << "Скидка: " << discount << " рублей." << "\n";
    std::cout << "Рассчитываем стоимость..." << "\n";
    std::cout << "-----------------------------------------------------------------------------" << "\n";
    std::cout << "Полная стоимость футболки с учетом доставки и скидки составляет: " << fullPrice << " рублей." << "\n";
    std::cout << "-----------------------------------------------------------------------------" << "\n"; 
}