#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;

                    dfs(land, i, j, m, n, r2, c2);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>> &land, int i, int j, int m, int n, int &r2, int &c2)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || land[i][j] != 1)
            return;

        land[i][j] = -1;

        r2 = max(r2, i);
        c2 = max(c2, j);

        dfs(land, i + 1, j, m, n, r2, c2);
        dfs(land, i - 1, j, m, n, r2, c2);
        dfs(land, i, j + 1, m, n, r2, c2);
        dfs(land, i, j - 1, m, n, r2, c2);
    }
};