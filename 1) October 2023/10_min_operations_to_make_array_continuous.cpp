#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        set<int> temp(nums.begin(), nums.end());
        vector<int> newNums(temp.begin(), temp.end());
        int t = newNums.size();

        int ans = n, right = 0;
        for (int left = 0; left < t; left++)
        {
            while (right < t && newNums[right] < newNums[left] + n)
                right++;

            int window = right - left;
            ans = min(ans, n - window);
        }

        return ans;
    }
};