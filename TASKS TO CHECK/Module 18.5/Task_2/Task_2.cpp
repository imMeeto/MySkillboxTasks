#include <iostream>

int countWays(int n, int k = 3)
{
    if (n == 0) 
    {
        return 1;
    }
    if (n < 0) 
    {
        return 0;
    }

    int ways = 0;
    for (int i = 1; i <= k; ++i) 
    {
        ways += countWays(n - i, k);
    }

    return ways;
}

int main()
{
    int n, k;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;
    std::cout << "Enter the maximum jump length: ";
    std::cin >> k;

    if (k <= 0)
    {
        std::cout << "Number of ways: " << countWays(n) << "\n";
    } 
    else 
    {
        std::cout << "Number of ways: " << countWays(n, k) << "\n";
    }

    return 0;
}