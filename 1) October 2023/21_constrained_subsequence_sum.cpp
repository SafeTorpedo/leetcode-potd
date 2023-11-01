#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size());
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && i - dq.front() > k)
                dq.pop_front();

            if (!dq.empty())
                dp[i] = dp[dq.front()] + nums[i];
            else
                dp[i] = nums[i];

            while (!dq.empty() && dp[dq.back()] < dp[i])
                dq.pop_back();

            if (dp[i] > 0)
                dq.push_back(i);
        }

        return *max_element(dp.begin(), dp.end());
    }
};