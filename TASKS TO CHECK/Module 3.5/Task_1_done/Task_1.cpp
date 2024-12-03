#include <iostream>

int main()
{

   std::string oneStop = "«Улица программистов»";
   std::string twoStop = "«Проспект алгоритмов»";
   std::string threeStop = "«Школа синтаксиса»";
   std::string fourStop = "«Микрорайон Питона Плюсовича»";


   // Первая остановка автобуса «Улица программистов»
   int startPassangers = 0;
   int currentPassengers = startPassangers;
   std::cout << "Прибываем на остановку " << oneStop << ". В салоне пассажиров: " << currentPassengers << "\n";
   int startLeftPassangers = 0;
   int leftPassengers = startLeftPassangers; 
   int incomingPassengers;
   std::cout << "Сколько пассажиров зашло на остановке? ";
   std::cin  >> incomingPassengers;
   int soldedTickets = (incomingPassengers * 20);
   currentPassengers += incomingPassengers;
   std::cout << "Отправляемся с остановки " << oneStop << ". В салоне пассажиров: " << currentPassengers << "\n";
   std::cout << "--------Едем--------" << "\n";

   // Вторая остановка автобуса «Проспект алгоритмов»
   std::cout << "Прибываем на остановку " << twoStop << ". В салоне пассажиров: " <<currentPassengers << "\n";
   std::cout << "Сколько пассажиров вышло на остановке?: ";
   std::cin  >> leftPassengers;
   std::cout << "Сколько пассажиров зашло на остановке? ";
   std::cin  >> incomingPassengers;
   soldedTickets += (incomingPassengers * 20);
   currentPassengers += incomingPassengers -= leftPassengers;
   std::cout << "Отправляемся с остановки " << twoStop << ". В салоне пассажиров: " << currentPassengers << "\n";
   std::cout << "--------Едем--------" << "\n";

   // Третья остановка автобуса «Школа синтаксиса»
   std::cout << "Прибываем на остановку " << threeStop << ". В салоне пассажиров: " <<currentPassengers << "\n";
   std::cout << "Сколько пассажиров вышло на остановке?: ";
   std::cin  >> leftPassengers;
   std::cout << "Сколько пассажиров зашло на остановке? ";
   std::cin  >> incomingPassengers;
   soldedTickets += (incomingPassengers * 20);
   currentPassengers += incomingPassengers -= leftPassengers;
   std::cout << "Отправляемся с остановки " << threeStop << ". В салоне пассажиров: " << currentPassengers << "\n";
   std::cout << "--------Едем--------" << "\n";

   // Четвертая остановка автобуса «Микрорайон Питона Плюсовича»
   std::cout << "Прибываем на остановку " << fourStop << ". В салоне пассажиров: " <<currentPassengers << "\n";
   std::cout << "Сколько пассажиров вышло на остановке?: ";
   std::cin  >> leftPassengers;
   std::cout << "Сколько пассажиров зашло на остановке? ";
   std::cin  >> incomingPassengers;
   soldedTickets += (incomingPassengers * 20);
   currentPassengers += incomingPassengers -= leftPassengers;
   std::cout << "Ожидаем на остановке " << fourStop << ". В салоне пассажиров: " << currentPassengers << "\n";

   // Расчет дохода
   std::cout << "--------Рассчитываем доход--------" << "\n";
   std::cout << "Всего заработали: " << soldedTickets << " руб." << "\n";
   int driverSalary = soldedTickets / 4;
   std::cout << "Зарплата водителя: " << driverSalary << " руб." << "\n";
   int fuelCosts = soldedTickets / 5;
   std::cout << "Расходы на топливо: " << fuelCosts << " руб." << "\n";
   int taxes = soldedTickets / 5;
   std::cout << "Налоги: " << taxes << " руб." << "\n";
   int carRepairCosts = soldedTickets / 5;
   std::cout << "Расходы на ремонт машины: " << carRepairCosts << " руб." << "\n";
   int profit = soldedTickets - driverSalary - fuelCosts - taxes - carRepairCosts;
   std::cout << "\n";
   std::cout << "---------------------" << "\n";
   std::cout << "Итого доход: " << profit << " руб." << "\n";
   std::cout << "---------------------" << "\n"; 
}