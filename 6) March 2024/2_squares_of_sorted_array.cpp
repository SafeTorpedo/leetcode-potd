#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1, k = j;
        vector<int> ans(k + 1, 0);
        while (k >= 0)
        {
            if (abs(nums[i]) > abs(nums[j]))
                ans[k--] = nums[i] * nums[i++];
            else
                ans[k--] = nums[j] * nums[j--];
        }
        return ans;
    }
};