#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 1)
            return true;

        if (n <= 0)
            return false;

        double x = log(n) / log(4);

        return x == (int)x;
    }
};