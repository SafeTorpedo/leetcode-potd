#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
            return n - 1;

        int quotient = n / 3;
        long long ans = pow(3, quotient);

        if (n % 3 == 1)
        {
            ans /= 3;
            ans *= 4;
        }
        else if (n % 3 == 2)
            ans *= 2;

        return ans;
    }
};