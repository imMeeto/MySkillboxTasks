#include <iostream>

int main() {

    int firstItemPrice;
    int secondItemPrice;
    int thirdItemPrice;
    int deliveryCost;
    std::cout << "----Калькулятор стоимости корзины----" << "\n";
    std::cout << "В вашей корзине 3 товара." << "\n";
    std::cout << "Акция: при покупке товаров на сумму более 10000 рублей вы получите скидку 10%!" << "\n";
    std::cout << "Введите стоимость первого товара: ";
    std::cin >> firstItemPrice;

    std::cout << "Введите стоимость второго товара: ";
    std::cin >> secondItemPrice;

    std::cout << "Введите стоимость третьего товара: ";
    std::cin >> thirdItemPrice;

    std::cout << "Введите стоимость доставки: ";
    std::cin >> deliveryCost;

    int fullItemPrice = firstItemPrice + secondItemPrice + thirdItemPrice;
    int lastPrice = fullItemPrice + deliveryCost;
    lastPrice = fullItemPrice + deliveryCost;
    
    if (fullItemPrice >= 10000)
    {
        lastPrice = fullItemPrice - (fullItemPrice * (10/100));
        std::cout << "Стоимость товара превышает 10000 рублей, поэтому вы получаете скидку 10%!" << "\n";
        std::cout << "Рассчитываем стоимость корзины..." << "\n";
        std::cout << "---------------------------------" << "\n";
        std::cout << "К оплате: " << lastPrice << "\n";
    }
        if (fullItemPrice < 10000)
        {
            std::cout << "Рассчитываем стоимость корзины..." << "\n";
            std::cout << "---------------------------------" << "\n";
            std::cout << "К оплате: " << lastPrice << "\n";
        }
}