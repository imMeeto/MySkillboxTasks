#include <iostream>

int main() {
    const int SIZE = 15; // Размер массива
    float arr[SIZE];     // Массив для хранения чисел

    // Ввод 15 дробных чисел
    std::cout << "*Sort the numbers!*\n";
    std::cout << "Input 15 float numbers: \n";
    for (int i = 0; i < SIZE; i++) {
      std::cin >> arr[i];
    }

    // Сортировка выбором (по убыванию)
    for (int i = 0; i < SIZE - 1; i++) {
        int maxIndex = i; // Индекс максимального элемента
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j; // Нашли новый максимальный элемент
            }
        }
        // Меняем местами текущий элемент и максимальный
        if (maxIndex != i) {
          std::swap(arr[i], arr[maxIndex]);
        }
    }

    // Вывод отсортированного массива
    std::cout << "Sorted numbers: ";
    for (int i = 0; i < SIZE; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}