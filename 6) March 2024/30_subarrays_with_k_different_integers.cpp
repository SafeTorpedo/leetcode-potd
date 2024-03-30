#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }

private:
    int helper(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        unordered_map<int, int> mp;
        int ans = 0;

        while (right < nums.size())
        {
            mp[nums[right]]++;

            while (mp.size() > k)
            {
                mp[nums[left]]--;

                if (mp[nums[left]] == 0)
                    mp.erase(nums[left]);

                left++;
            }

            ans += right - left + 1;
            right++;
        }

        return ans;
    }
};