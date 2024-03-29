#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long ans = 0;
        int element = *max_element(nums.begin(), nums.end());
        int left = 0, right = 0, count = 0;

        while (right < nums.size())
        {
            if (nums[right] == element)
                count++;

            if (count == k)
            {
                while (nums[left] != element)
                {
                    left++;
                }

                left++;
                count--;
            }

            ans += left;
            right++;
        }

        return ans;
    }
};