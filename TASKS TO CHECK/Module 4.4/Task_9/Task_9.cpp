#include <iostream>

int main() {
  int salary;
  float cumulativeTax;

  std::cout << "Рассчитайте сумму налога по прогрессивной шкале в зависимости от Вашего дохода!" << "\n";
  std::cout << "---------------------" << "\n";

	while (true) {
		cumulativeTax = 0;

		while (true) {
      std::cout << "Введите Ваш доход: ";
      std::cin >> salary;

      if (salary >= 1000) {
        break;
      	} else {
            std::cout << "Вы ввели неверное значение! Введите значение от 1000!" << "\n";
      }    
    }

    std::cout << "Производим рассчет..." << "\n";
    std::cout << "---------------------" << "\n";
    

			if (salary > 50000) {
					cumulativeTax += (salary - 50000) * 0.30; // 30% на доход выше 50,000
					salary = 50000; // уменьшаем доход до 50к для следующего расчета
			}
			
			if (salary > 10000) {
					cumulativeTax += (salary - 10000) * 0.20; // 20% на доход от 10,000 до 50,000
					salary = 10000; // уменьшаем доход до 10к для следующего расчета
			}
    
    cumulativeTax = cumulativeTax + salary * 0.13; // 13% на доход до 10к
    std::cout << "Налог равен: " << cumulativeTax << "\n";
	
			while (true) {
					std::cout << "Хотите продолжить? (1 - да; 2 - нет): ";
					int answer;
					std::cin >> answer;

				if (answer == 1) {
					std::cout << "Отлично! Давайте продолжим!" << "\n";
					break;
				} else if (answer == 2) {
					std::cout << "Хорошо! Увидимся!" << "\n";
					return 0;
				} else {
					std::cout << "Вы ввели неверное значение! Введите 1 или 2!" << "\n";
				}
			}
	}
}