#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        memset(dp, -1, sizeof(dp));
        return helper(cost, time, 0, time.size());
    }

private:
    int dp[501][501];

    int helper(vector<int> &cost, vector<int> &time, int i, int totalTime)
    {
        if (totalTime <= 0)
            return 0;

        if (i >= cost.size())
            return 1e9;

        if (dp[i][totalTime] != -1)
            return dp[i][totalTime];

        int notPaint = helper(cost, time, i + 1, totalTime);
        int paint = cost[i] + helper(cost, time, i + 1, totalTime - time[i] - 1);
        return dp[i][totalTime] = min(notPaint, paint);
    }
};