#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int ans = k;
        for (int num : nums)
            ans ^= num;

        return __builtin_popcount(ans);
    }
};