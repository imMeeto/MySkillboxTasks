#include <iostream>

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Проверка строк
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Проверка столбцов
        }
    }
    return false;
}

int main() {
  std::cout << "*The tic tac toe game!*";
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int moves = 0; // Счётчик ходов
    char currentPlayer = 'X'; // Начинает игрок X
    bool gameOver = false; // Флаг завершения игры

    while (moves < 9 && !gameOver) {
        std::cout << "\n";
        std::cout << "Current game board: \n";
        std::cout << "\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "-+-+-\n";
        }

        int row, col;
        std::cout << "\n";
        std::cout << "Gamer " << currentPlayer << ", where will you go? Input row and column (1-3):\n";
        std::cin >> row >> col;

        // Проверка корректности координат и доступности клетки
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
          board[row - 1][col - 1] = currentPlayer;
          moves++;

            if (checkWin(board, currentPlayer)) {
                std::cout << "\n";
                std::cout << "Player " << currentPlayer << " wins! \n";
                gameOver = true;
            }

            // Смена игрока
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "\n";
            std::cout << "Incorrect coordinates or the cell is already occupied. Try again.\n";
        }
    }

    // Если все ходы сделаны и никто не победил
    if (!gameOver) {
        std::cout << "\n";
        std::cout << "Draw!\n";
    }

    std::cout << "\n";
    std::cout << "Result game board: \n";
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "-+-+-\n";
    }
    
    std::cout << "\n";
    return 0;
}