#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int ans = 0;

        for (int i : nums)
            m[i]++;

        for (auto i : m)
        {
            int count = i.second;
            if (count > 1)
                ans += (count * (count - 1)) / 2;
        }

        return ans;
    }
};