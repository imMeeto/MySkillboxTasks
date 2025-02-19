#include <iostream>
#include <vector>

int main() {
    std::cout << "*Delete number from your vector.*\n";
    
    // Ввод размера вектора
    int vecSize = 0;
    std::cout << "Input vector size: ";
    std::cin >> vecSize;

    // Создание вектора и ввод элементов
    std::vector<int> vec(vecSize);
    std::cout << "Input numbers: \n";
    for (int i = 0; i < vecSize; ++i) {
        std::cin >> vec[i];
    }

    // Ввод числа для удаления
    int deleteNum = 0;
    std::cout << "Input number to delete: ";
    std::cin >> deleteNum;

    // Удаление элементов, равных deleteNum, in-place
    int newSize = 0;
    for (int i = 0; i < vecSize; ++i) {
        if (vec[i] != deleteNum) {
            vec[newSize] = vec[i];
            newSize++;
        }
    }

    // Удаление лишних элементов с конца вектора
    while ((int)vec.size() > newSize) {
        vec.pop_back();
    }

    // Вывод результата
    std::cout << "Result: ";
    for (int i = 0; i < newSize; ++i) {
        std::cout << vec[i] << " "; // Добавляем пробел между числами
    }
    std::cout << "\n";

    return 0;
}