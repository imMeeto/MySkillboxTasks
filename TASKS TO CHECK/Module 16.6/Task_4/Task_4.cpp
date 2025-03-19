#include <iostream>
#include <string>

enum note 
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main()
{
    std::string input;
    int chord = 0;

    std::cout << "Input the chord (numbers from 1 to 7): ";
    std::cin >> input;

    for (char c : input)
    {
        int noteIndex = c - '1';  // Преобразуем символ в индекс (0-6)
        if (noteIndex >= 0 && noteIndex < 7) // Проверяем, что индекс корректен
        { 
            chord |= (1 << noteIndex);  // Устанавливаем соответствующий бит
        }
    }

    std::cout << "A chord contains notes: ";
    if (chord & DO) std::cout << "DO ";
    if (chord & RE) std::cout << "RE ";
    if (chord & MI) std::cout << "MI ";
    if (chord & FA) std::cout << "FA ";
    if (chord & SOL) std::cout << "SOL ";
    if (chord & LA) std::cout << "LA ";
    if (chord & SI) std::cout << "SI ";
    std::cout << "\n";

    return 0;
}