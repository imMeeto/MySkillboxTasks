#include <iostream>
#include <string>

int main() {
    std::cout << "Bulls and cows game. \n";
    std::string firstNumber, secondNumber;
    
    while (true) {
        std::cout << "[Player 1]: Input the desired number (4 digits): ";
        std::cin >> firstNumber;
        if (firstNumber.length() != 4) {
            std::cout << "[Error]: Input 4 digits.\n";
            continue;
        } else {
            break;
        }
    }
    
    while (true) {
        std::cout << "[Player 2]: Input the second number (4 digits): ";
        std::cin >> secondNumber;
        if (secondNumber.length() != 4) {
            std::cout << "[Error]: Input 4 digits.\n";
            continue;
        } else {
            break;
        }
    }
    
    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < 4; ++i) {
        if (firstNumber[i] == secondNumber[i]) {
            ++bulls;
            firstNumber[i] = '-';
            secondNumber[i] = '-';
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (firstNumber[i] != '-') {
            for (int j = 0; j < 4; ++j) {
                if (secondNumber[j] != '-' && firstNumber[i] == secondNumber[j]) {
                    ++cows;
                    secondNumber[j] = '-';
                    break;
                }
            }
        }
    }

    std::cout << "[Game]: Bulls: " << bulls << ", cows: " << cows << "\n";
    return 0;
}