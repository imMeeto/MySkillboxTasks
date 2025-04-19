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

const std::string DATA_FILE = "TransactionInfo.txt";

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

void addInfoToFile(const std::string& DATA_FILE, const TransactionInfo& transaction)
{
  std::ofstream file(DATA_FILE, std::ios::app);
  if (!file.is_open())
  {
    std::cout << "Error opening file: " << DATA_FILE << std::endl;
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

  std::cout << "\nInput next info: \n";

  std::cout << "- First name: ";
  std::cin >> transaction.firstName;

  std::cout << "- Last name: ";
  std::cin >> transaction.lastName;

  do
  {
    std::cout << "- Date (DD.MM.YYYY): ";
    std::cin >> transaction.date;
    if (!isValidDate(transaction.date))
    {
      std::cout << "\nInvalid date format. Please try again.\n";
    }
  } while (!isValidDate(transaction.date));
  
  std::cout << "- Input payment amount: ";
  std::cin >> transaction.paidAmount;

  std::cin.ignore(); 

  return transaction;
}

void showTransactionInfo()
{
  std::ifstream showFile(DATA_FILE);
  if (!showFile.is_open())
  {
      std::cout << "Error opening file for reading!\n";
      return;
  }

  std::cout << "\nCurrent transactions:\n";
  std::cout << "----------------------\n";

  TransactionInfo transaction;

  while (showFile >> transaction.firstName 
                  >> transaction.lastName   
                  >> transaction.date   
                  >> transaction.paidAmount)
  {
    std::cout << "Name: " << transaction.firstName << " " << transaction.lastName << "\n";
    std::cout << "Date: " << transaction.date << "\n";
    std::cout << "Amount: " << transaction.paidAmount << "\n";
    std::cout << "----------------------\n";
  }
  
}

int main()
{
std::cout << "*** Payment transaction entry system ***\n";

while (true)
{
  std::cout << "\nUse next command: \n";
  std::cout << "- 'list' (show current transactions)\n";
  std::cout << "- 'add' (add new entry)\n";
  std::cout << "- 'exit' (quit program)\n";
  
  std::string command;
  std::cout << "Input command: ";
  std::getline(std::cin, command);

  if (command == "list")
  {
    showTransactionInfo();
  }
  else if (command == "add")
  {

    TransactionInfo transaction = getTransactionInfo();
    addInfoToFile(DATA_FILE, transaction);
    std::cout << "Record added successfully!\n";
  }
  else if (command == "exit")
  {
    break;
  }
  else
  {
    std::cout << "Unknown command! Try again.\n";
  }
}

std::cout << "\nGoodbye! Data saved to: " << DATA_FILE << std::endl;
return 0;
}