#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));

        n = grid.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            ans = min(ans, solve(grid, 0, i));
        }

        return ans;
    }

private:
    int dp[201][201];
    int n;

    int solve(vector<vector<int>> &grid, int row, int col)
    {
        if (row == n - 1)
            return grid[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int sum = INT_MAX;
        for (int nextCol = 0; nextCol < n; nextCol++)
        {
            if (nextCol != col)
                sum = min(sum, solve(grid, row + 1, nextCol));
        }

        return dp[row][col] = grid[row][col] + sum;
    }
};