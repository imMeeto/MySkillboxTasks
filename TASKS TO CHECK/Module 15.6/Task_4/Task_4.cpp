#include <iostream>
#include <vector>
#include <cmath> 

void printSortedByAbsoluteValue(std::vector<int> nums) 
{
    int firstPositive = 0;
    while (firstPositive < nums.size() && nums[firstPositive] < 0) 
    {
        firstPositive++;
    }

    // Левый указатель (начинается с последнего отрицательного числа)
    int left = firstPositive - 1;
    // Правый указатель (начинается с первого положительного числа)
    int right = firstPositive;

    while (left >= 0 || right < nums.size()) 
    {
        if (left >= 0 && (right >= nums.size() || std::abs(nums[left]) <= std::abs(nums[right]))) 
        {
            // Если левый указатель в пределах массива и его число меньше или равно по модулю
            std::cout << nums[left] << " ";
            left--; // Двигаем левый указатель влево
        } 
        else if (right < nums.size()) 
        {
            // Если правый указатель в пределах массива
            std::cout << nums[right] << " ";
            right++; // Двигаем правый указатель вправо
        }
    }
    std::cout << "\n";
}

int main()
{
    std::cout << "*Sort the array in ascending order of the modulus of the numbers.*\n";
    std::cout << "*Array: {−100, −50, −5, 1, 10, 15}*\n";
    std::cout << "Result: ";

    std::vector<int> nums = {-100, -50, -5, 1, 10, 15};
    printSortedByAbsoluteValue(nums);

    return 0;
}