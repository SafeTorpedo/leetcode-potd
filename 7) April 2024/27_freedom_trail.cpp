#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        m = ring.size();
        n = key.size();
        for (int i = 0; i < m; i++)
            mp[ring[i]].push_back(i);

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, key);
    }

private:
    int m, n;
    unordered_map<char, vector<int>> mp;
    int dp[101][101];

    int countSteps(int ringIdx, int nextIdx)
    {
        int dist = abs(ringIdx - nextIdx);
        int wrapDist = m - dist;

        return min(dist, wrapDist);
    }

    int solve(int ringIdx, int keyIdx, string &key)
    {
        if (keyIdx == n)
            return 0;

        if (dp[ringIdx][keyIdx] != -1)
            return dp[ringIdx][keyIdx];

        char ch = key[keyIdx];
        int ans = INT_MAX;
        for (int nextIdx : mp[ch])
        {
            int totalSteps = 1 + countSteps(ringIdx, nextIdx) + solve(nextIdx, keyIdx + 1, key);
            ans = min(ans, totalSteps);
        }

        return dp[ringIdx][keyIdx] = ans;
    }
};