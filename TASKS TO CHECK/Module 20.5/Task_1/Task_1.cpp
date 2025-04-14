#include <iostream>
#include <fstream>
#include <string>

struct TransactionInfo
{
  std::string firstName;
  std::string lastName;
  std::string date;
  double paidAmount;
};

bool isValidDate(const std::string& date) //(DD.MM.YYYY)
{
  if (date.length() != 10 || date[2] != '.' || date[5] != '.') return false;

  int day = std::stoi(date.substr(0, 2));
  int month = std::stoi(date.substr(3, 2));
  int year = std::stoi(date.substr(6, 4));

  if (day < 1 || day > 31) return false;
  if (month < 1 || month > 12) return false;
  if (year < 1920 || year > 2050) return false;

  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

  return true;
}

void addInfoToFile(const std::string& filePath, const TransactionInfo& transaction)
{
  std::ofstream file(filePath, std::ios::app);
  if (!file.is_open())
  {
    std::cout << "Error opening file: " << filePath << std::endl;
    exit(1);
  }
  
  std::cout << std::endl;

  file << transaction.firstName << " " << transaction.lastName << " "
            << transaction.date << " " << transaction.paidAmount << std::endl;

  file.close();
}

TransactionInfo getTransactionInfo()
{
  TransactionInfo transaction;

  std::cout << "- Input first name: ";
  std::cin >> transaction.firstName;

  std::cout << "- Input first name: ";
  std::cin >> transaction.lastName;

  do
  {
    std::cout << "- Input date (DD.MM.YYYY): ";
    std::cin >> transaction.date;
    if (!isValidDate(transaction.date))
    {
      std::cout << "\nInvalid date format. Please try again.\n";
    }
  } while (!isValidDate(transaction.date));
  
  std::cout << "- Input payment amount: ";
  std::cin >> transaction.paidAmount;

  return transaction;
}

int main()
{
  std::cout << "*** Payment transaction entry system ***\n";

  std::cout << "To get started, input the full path to Transaction Info file: \n";
  std::string filePath;
  std::getline(std::cin, filePath);

  std::cout << "\nGood! Input next info: \n";

  char choice;
  do
  {
    TransactionInfo transaction = getTransactionInfo();
    addInfoToFile(filePath, transaction);
    
    std::cout << "\nRecord added successfully!\n";
    std::cout << "Add another record? (y/n): ";
    std::cin >> choice;
  } while (choice == 'y' || choice == 'Y');

  std::cout << "\nGoodbye! Records saved to:\n" << filePath << std::endl;
  return 0;
}