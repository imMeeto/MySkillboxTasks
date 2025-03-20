#include <iostream>

void evendigits(long long n, int &ans)
{
    if (n == 0)
    {
        return;
    }

    int lastDigit = n % 10;

    if (lastDigit % 2 == 0)
    {
        ans++;
    }

    evendigits(n / 10, ans);
}

int main()
{
    long long n = 9223372036854775806;
    int ans = 0;

    evendigits(n, ans);

    std::cout << "ans = " << ans << "\n";

    return 0;
}