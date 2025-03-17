#include <iostream>
#include <vector>

std::vector<int> a = {2, 7, 11, 15};
int target = 9;

void findPairWithSum(const std::vector<int> nums, int target) 
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                std::cout << "Pair: " << nums[i] << " and " << nums[j] << "\n";
                return; 
            }
        }
    }

    std::cout << "The pair was not found!" << "\n";
}

int main()
{
    findPairWithSum(a, target);

    return 0;
}