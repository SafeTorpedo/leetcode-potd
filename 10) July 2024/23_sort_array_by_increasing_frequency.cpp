#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;

        auto lambda = [&](int &a, int &b)
        {
            if (mp[a] == mp[b])
                return a > b;

            return mp[a] < mp[b];
        };

        sort(nums.begin(), nums.end(), lambda);
        return nums;
    }
};