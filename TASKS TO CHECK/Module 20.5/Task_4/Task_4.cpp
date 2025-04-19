#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

const int DENOMINATIONS[] = {5000, 2000, 1000, 500, 200, 100};
const int NUM_DENOMINATIONS = 6;
const int MAX_BILLS = 1000;  // Maximum total number of bills
const std::string DATA_FILE = "atm_state.bin";

int bills[NUM_DENOMINATIONS] = {0};

int getTotalBillsCount()
{
    int totalBills = 0;
    for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
      totalBills += bills[i];
    }
    return totalBills;
}

void loadState()
{
    std::ifstream inFile(DATA_FILE);
    if (inFile)
    {
        for (int i = 0; i < NUM_DENOMINATIONS; ++i)
        {
            inFile >> bills[i];
        }
    }
}

void saveState()
{
    std::ofstream outFile(DATA_FILE);
    for (int i = 0; i < NUM_DENOMINATIONS; ++i)
    {
        outFile << bills[i] << " ";
    }
}

void showBalance()
{
    int totalMoney = 0;
    int totalBills = 0;
    std::cout << "ATM Balance:\n";
    for (int i = 0; i < NUM_DENOMINATIONS; ++i)
    {
        std::cout << DENOMINATIONS[i] << " RUB: " << bills[i] << " bills\n";
        totalMoney += DENOMINATIONS[i] * bills[i];
        totalBills += bills[i];
    }
    std::cout << "Total: " << totalMoney << " RUB (" << totalBills << "/" << MAX_BILLS << " bills)\n\n";
}

void addMoney()
{
    int currentBills = getTotalBillsCount();
    if (currentBills >= MAX_BILLS) {
        std::cout << "ATM is full! Cannot add more bills.\n";
        return;
    }

    srand(time(0));
    int billsToAdd = MAX_BILLS - currentBills;
    for (int i = 0; i < billsToAdd; ++i)
    {
        bills[rand() % NUM_DENOMINATIONS]++;
    }
    std::cout << "ATM refilled! Added " << billsToAdd << " bills.\n";
}

bool withdrawMoney(int amount)
{
    if (amount % 100 != 0)
    {
        std::cout << "Error: Amount must be multiple of 100 RUB.\n";
        return false;
    }

    int temp[NUM_DENOMINATIONS];
    std::copy(bills, bills + NUM_DENOMINATIONS, temp);

    for (int i = 0; i < NUM_DENOMINATIONS && amount > 0; ++i)
    {
        int count = std::min(amount / DENOMINATIONS[i], temp[i]);
        amount -= count * DENOMINATIONS[i];
        temp[i] -= count;
    }

    if (amount == 0)
    {
        std::copy(temp, temp + NUM_DENOMINATIONS, bills);
        std::cout << "Withdrawal successful!\n";
        return true;
    }
    std::cout << "Insufficient bills!\n";
    return false;
}

int main()
{
    loadState();
    showBalance();

    std::string cmd;
    while (true)
    {
        std::cout << "Commands: + (refill), - (withdraw), q (quit)\n> ";
        std::cin >> cmd;

        if (cmd == "+") addMoney();
        else if (cmd == "-")
        {
            int amount;
            std::cout << "Amount: ";
            std::cin >> amount;
            withdrawMoney(amount);
        }
        else if (cmd == "q") break;
        
        showBalance();
    }

    saveState();
    std::cout << "Saved to " << DATA_FILE << "\n";
    return 0;
}