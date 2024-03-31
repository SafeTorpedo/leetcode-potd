#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int minPosition = -1, maxPosition = -1, culpritIndex = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == minK)
                minPosition = i;

            if (nums[i] == maxK)
                maxPosition = i;

            if (nums[i] < minK || nums[i] > maxK)
                culpritIndex = i;

            int smaller = min(minPosition, maxPosition);
            int temp = smaller - culpritIndex;

            ans += (temp < 0) ? 0 : temp;
        }

        return ans;
    }
};