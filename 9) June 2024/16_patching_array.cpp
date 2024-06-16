#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int m = nums.size();
        int patch = 0, i = 0;
        long maxReach = 0;

        while (maxReach < n)
        {
            if (i < m && nums[i] <= maxReach + 1)
            {
                maxReach += nums[i];
                i++;
            }
            else
            {
                maxReach += (maxReach + 1);
                patch++;
            }
        }

        return patch;
    }
};