#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int>(rows));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
                ans[j][i] = matrix[i][j];
        }

        return ans;
    }
};