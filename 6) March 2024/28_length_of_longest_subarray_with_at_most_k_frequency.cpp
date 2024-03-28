#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        int ans = 0;

        unordered_map<int, int> mp;

        while (right < nums.size())
        {
            mp[nums[right]]++;

            while (mp[nums[right]] > k)
            {
                mp[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};