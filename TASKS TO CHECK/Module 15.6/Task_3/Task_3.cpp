#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    std::vector<int> nums; // Вектор для хранения чисел
    int input;

    std::cout << "*Display the fifth oldest number from the inputed array.*\n";
    std::cout << "*Input -1 to get the result. Input -2 to end the program.*\n";

    while (true) 
    {
        std::cout << "Input a number: ";
        std::cin >> input;

        if (input == -1) 
        {
            // Вывод текущего массива
            std::cout << "Current array: ";
            for (int num : nums) 
            {
                std::cout << num << " ";
            }
            std::cout << "\n";

            // Проверка, есть ли пятое число
            if (nums.size() >= 5) 
            {
                std::cout << "The fifth number in the array: " << nums[4] << "\n";
            } 
            else 
            {
                std::cout << "There are not enough numbers to output the fifth.\n";
            }
        } 
        else if (input == -2) 
        {
            // Завершение программы
            break;
        } 
        else 
        {
            // Добавление нового числа в вектор
            if (nums.size() < 5) 
            {
                nums.push_back(input); // Добавляем число, если в векторе меньше пяти чисел
                std::sort(nums.begin(), nums.end()); // Сортируем вектор
            } 
            else if (input < nums[4]) 
            {
                nums[4] = input; // Заменяем максимальное число в векторе
                std::sort(nums.begin(), nums.end()); // Сортируем вектор
            }
        }
    }

    return 0;
}