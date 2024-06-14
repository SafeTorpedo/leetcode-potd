#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                int increment = nums[i - 1] + 1 - nums[i];
                ans += increment;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return ans;
    }
};