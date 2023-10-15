#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        arrLen = min(arrLen, steps);
        vector<int> dp(arrLen, 0);
        vector<int> prevDp(arrLen, 0);
        prevDp[0] = 1;
        int MOD = 1e9 + 7;

        for (int i = 1; i <= steps; i++)
        {
            dp = vector(arrLen, 0);

            for (int j = arrLen - 1; j >= 0; j--)
            {
                int ans = prevDp[j];

                if (j > 0)
                    ans = (ans + prevDp[j - 1]) % MOD;

                if (j < arrLen - 1)
                    ans = (ans + prevDp[j + 1]) % MOD;

                dp[j] = ans;
            }

            prevDp = dp;
        }

        return dp[0];
    }
};