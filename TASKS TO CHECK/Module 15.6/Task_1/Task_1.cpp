#include <iostream>
#include <vector>
#include <climits>

std::vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

std::pair<int, int> findMaxSubarray() {
    int max_sum = INT_MIN;
    int current_sum = 0;
    int start = 0;
    int end = 0;
    int temp_start = 0;

    for (int i = 0; i < a.size(); ++i) {
        current_sum += a[i];

        // Если текущая сумма больше максимальной, обновляем максимум и индексы
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }

        // Если текущая сумма становится отрицательной, сбрасываем её
        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1; // Начинаем новый подмассив со следующего элемента
        }
    }

    return {start, end};
}

int main() {
    std::pair<int, int> result = findMaxSubarray();

    std::cout << "Indexes: " << result.first << " и " << result.second << "\n";
    return 0;
}