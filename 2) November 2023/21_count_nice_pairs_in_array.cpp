#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        vector<int> revNums;
        for (int num : nums)
            revNums.push_back(num - rev(num));

        unordered_map<int, int> mp;
        int ans = 0;
        int MOD = 1e9 + 7;
        for (int num : revNums)
        {
            ans = (ans + mp[num]) % MOD;
            mp[num]++;
        }

        return ans;
    }

private:
    int rev(int num)
    {
        int ans = 0;
        while (num > 0)
        {
            ans = ans * 10 + num % 10;
            num /= 10;
        }

        return ans;
    }
};