#include <iostream>
#include <fstream>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
#include <string>

const int DENOMINATIONS[] = {5000, 2000, 1000, 500, 200, 100};
const int NUM_DENOMINATIONS = 6;
const int MAX_BILLS = 1000;
const std::string DATA_FILE = "atm_state.txt";

int bills[NUM_DENOMINATIONS];

void initializeEmptyATM() {
    for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
        bills[i] = 0;
    }
}

void loadState() {
    std::ifstream inFile(DATA_FILE);
    if (inFile) {
        for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
            inFile >> bills[i];
        }
        inFile.close();
    } else {
        initializeEmptyATM();
    }
}

void saveState() {
    std::ofstream outFile(DATA_FILE);
    for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
        outFile << bills[i] << " ";
    }
    outFile.close();
}

void displayStatus() {
    int total = 0;
    std::cout << "Текущее состояние банкомата:\n";
    for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
        std::cout << "Купюр " << DENOMINATIONS[i] << " руб.: " << bills[i] << "\n";
        total += DENOMINATIONS[i] * bills[i];
    }
    std::cout << "Общая сумма: " << total << " руб.\n\n";
}

int getTotalBills() {
    int total = 0;
    for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
        total += bills[i];
    }
    return total;
}

void fillATM() {
    srand(time(0));
    int currentBills = getTotalBills();
    int billsToAdd = MAX_BILLS - currentBills;

    for (int i = 0; i < billsToAdd; ++i) {
        int randomIndex = rand() % NUM_DENOMINATIONS;
        bills[randomIndex]++;
    }

    std::cout << "Банкомат пополнен.\n";
    displayStatus();
}

bool withdrawMoney(int amount) {
    if (amount % 100 != 0) {
        std::cout << "Сумма должна быть кратна 100 руб.\n";
        return false;
    }

    int tempBills[NUM_DENOMINATIONS];
    for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
        tempBills[i] = bills[i];
    }

    int remaining = amount;
    for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
        if (remaining <= 0) break;
        
        int denom = DENOMINATIONS[i];
        int needed = remaining / denom;
        int available = tempBills[i];
        int taken = (needed < available) ? needed : available;
        
        remaining -= taken * denom;
        tempBills[i] -= taken;
    }

    if (remaining == 0) {
        for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
            bills[i] = tempBills[i];
        }
        std::cout << "Выдано " << amount << " руб.\n";
        displayStatus();
        return true;
    } else {
        std::cout << "Невозможно выдать запрошенную сумму. Недостаточно купюр в банкомате.\n";
        return false;
    }
}

int main() {
    loadState();
    displayStatus();

    std::string command;
    while (true) {
        std::cout << "Введите команду ('+' - пополнить, '-' - снять, 'q' - выйти): ";
        std::cin >> command;

        if (command == "+") {
            fillATM();
        } else if (command == "-") {
            int amount;
            std::cout << "Введите сумму для снятия (кратную 100 руб.): ";
            std::cin >> amount;
            withdrawMoney(amount);
        } else if (command == "q") {
            break;
        } else {
            std::cout << "Неизвестная команда. Попробуйте снова.\n";
        }
    }

    saveState();
    return 0;
}