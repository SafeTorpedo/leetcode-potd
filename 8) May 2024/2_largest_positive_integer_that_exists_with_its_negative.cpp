#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_set<int> seen;
        int ans = -1;

        for (int num : nums)
        {
            int absNum = abs(num);

            if (absNum > ans && seen.contains(-num))
                ans = absNum;
            else
                seen.insert(num);
        }

        return ans;
    }
};