#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> degree(n, 0);

        for (auto &road : roads)
        {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
        }

        long long importance = 1;
        long long ans = 0;

        sort(degree.begin(), degree.end());

        for (int i = 0; i < n; i++)
        {
            ans += (degree[i] * importance);
            importance++;
        }

        return ans;
    }
};