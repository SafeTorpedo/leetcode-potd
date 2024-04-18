#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, m, n, ans);

                    return ans;
                }
            }
        }

        return 0;
    }

private:
    void dfs(vector<vector<int>> &grid, int i, int j, int m, int n, int &ans)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            ans++;
            return;
        }

        if (grid[i][j] == -1)
            return;

        grid[i][j] = -1;

        dfs(grid, i + 1, j, m, n, ans);
        dfs(grid, i - 1, j, m, n, ans);
        dfs(grid, i, j - 1, m, n, ans);
        dfs(grid, i, j + 1, m, n, ans);
    }
};