#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (mat[row][col] == 1)
                {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }

        int ans = 0;

        for (int row = 0; row < m; row++)
        {
            if (rowCount[row] == 1)
            {
                for (int col = 0; col < n; col++)
                {
                    if (colCount[col] == 1 && mat[row][col] == 1)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};