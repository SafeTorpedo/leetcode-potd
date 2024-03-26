#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                nums[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;

            if (index == -1 || index > n - 1)
                continue;

            if (nums[index] == 0)
                nums[index] = -(n + 1);
            else if (nums[index] < 0)
                continue;
            else
                nums[index] = -nums[index];
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
                return i + 1;
        }

        return n + 1;
    }
};