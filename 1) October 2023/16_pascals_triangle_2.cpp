#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> pascal(2);

        pascal[0].push_back(1);

        for (int currentRow = 1; currentRow <= rowIndex; currentRow++)
        {
            pascal[1].push_back(1);

            vector<int> &currentRowList = pascal[1];
            vector<int> &previousRowList = pascal[0];

            for (int j = 1; j < previousRowList.size(); j++)
            {
                int sum = previousRowList[j] + previousRowList[j - 1];
                currentRowList.push_back(sum);
            }

            currentRowList.push_back(1);

            pascal[0] = pascal[1];
            pascal[1].clear();
        }

        return pascal[0];
    }
};