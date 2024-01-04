#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        int ans = 0;

        for (int num : nums)
            counter[num]++;

        for (auto &[_, count] : counter)
        {
            if (count == 1)
                return -1;

            ans += ceil((double)(count) / 3);
        }

        return ans;
    }
};