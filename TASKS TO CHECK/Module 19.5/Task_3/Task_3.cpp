#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filePath;
    std::cout << "Input the path to the payroll file: ";
    std::getline(std::cin, filePath);

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cout << "Error! File was not found!\n";
        return 1;
    }

    std::string firstName, secondName, date;
    std::string fullName;
    double amount = 0;
    double totalAmount = 0;

    std::string maxPerson;
    double maxAmount = 0;

    while (file >> firstName >> secondName >> amount >> date)
    {
        fullName = firstName + " " + secondName;
        totalAmount += amount;

        if (amount > maxAmount)
        {
            maxAmount = amount; 
            maxPerson = fullName;
        }
    }

    file.close();

    std::cout << "Total amount of payments: " << totalAmount << "\n";
    std::cout << "The person with the maximum payout amount: " << maxPerson << " (" << maxAmount << ")\n";

    return 0;
}