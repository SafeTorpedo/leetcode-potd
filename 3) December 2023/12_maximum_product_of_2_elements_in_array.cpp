#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int first = 0, second = 0;

        for (int num : nums)
        {
            if (num > first)
            {
                second = first;
                first = num;
            }
            else
                second = max(second, num);
        }

        return (first - 1) * (second - 1);
    }
};