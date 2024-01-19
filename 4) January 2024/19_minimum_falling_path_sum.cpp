#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();

        for (int i = 1; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (j == 0)
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                else if (j == columns - 1)
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                else
                    matrix[i][j] += min({matrix[i - 1][j], matrix[i - 1][j + 1], matrix[i - 1][j - 1]});
            }
        }

        int sum = INT_MAX;

        for (int i = 0; i < columns; i++)
            sum = min(sum, matrix[rows - 1][i]);

        return sum;
    }
};