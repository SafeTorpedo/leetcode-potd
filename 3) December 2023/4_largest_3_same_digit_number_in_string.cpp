#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        char maxDigit = '\0';

        for (int i = 0; i <= num.size() - 3; i++)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
                maxDigit = max(maxDigit, num[i]);
        }

        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};