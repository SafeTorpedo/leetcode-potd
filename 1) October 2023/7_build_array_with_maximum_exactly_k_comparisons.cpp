#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfArrays(int n, int m, int k)
    {
        N = n, M = m, K = k;
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 0);
    }

private:
    int N, M, K;
    int dp[51][51][101];

    int helper(int index, int len, int large)
    {
        if (index == N)
        {
            if (len == K)
                return 1;

            return 0;
        }

        if (dp[index][len][large] != -1)
            return dp[index][len][large];

        int ans = 0;
        for (int i = 1; i <= M; i++)
        {
            if (i > large)
                ans += helper(index + 1, len + 1, i);
            else
                ans += helper(index + 1, len, large);

            ans %= 1000000007;
        }

        return dp[index][len][large] = ans;
    }
};