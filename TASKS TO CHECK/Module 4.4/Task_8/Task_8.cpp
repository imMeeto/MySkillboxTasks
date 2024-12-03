#include <iostream>

int main() {
  std::cout << "Вычисляем разницу между самой высокой и самой низкой зарплатами сотрудников, ";
  std::cout << "а также среднее арифметическое зарплат всех сотрудников отдела." << "\n";
  std::cout << "------------------------------------------------------------------------------" << "\n";

  int firstEmpSalary;
  int secondEmpSalary;
  int thirdEmpSalary;

  std::cout << "Введите зарплату первого сотрудника: ";
  std::cin  >> firstEmpSalary;
  std::cout << "Введите зарплату второго сотрудника: ";
  std::cin 	>> secondEmpSalary;
  std::cout << "Введите зарплату третьего сотрудника: ";
  std::cin 	>> thirdEmpSalary;

	std::cout << "Считаем..." << "\n";
	std::cout << "-----------" << "\n";

	int maxSalary = firstEmpSalary;
	int minSalary = firstEmpSalary;

		if (secondEmpSalary > maxSalary) {
				maxSalary = secondEmpSalary;
			} if (thirdEmpSalary > maxSalary) {
				maxSalary = thirdEmpSalary;
			} if (secondEmpSalary < minSalary) {
				minSalary = secondEmpSalary;
			} if (thirdEmpSalary < minSalary) {
				minSalary = thirdEmpSalary;
			}
			
	int differenceSalary = maxSalary - minSalary;
	std::cout << "Разница между самой высокой и самой низкой зарплатой равна: " << differenceSalary << "\n";
	
	int arithmeticMean = (firstEmpSalary + secondEmpSalary + thirdEmpSalary) / 3;
	std::cout << "Среднее арифметичекое зарплат равно: " << arithmeticMean << "\n";
	
}