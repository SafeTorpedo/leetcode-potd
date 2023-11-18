#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        long head = 0, tail = 0, sum = 0;
        long long int ans = 0;

        for (head = 0; head < nums.size(); head++)
        {
            sum += nums[head];

            while ((long long)(head - tail + 1) * nums[head] - sum > k)
            {
                sum -= nums[tail];
                tail++;
            }
            ans = max(ans, (long long)(head - tail + 1));
        }
        return ans;
    }
};