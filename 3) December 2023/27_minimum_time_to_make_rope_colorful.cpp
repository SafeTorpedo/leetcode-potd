#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colorSequence, vector<int> &timeRequired)
    {
        int n = colorSequence.size();
        char previousColor = 'A';
        int previousTime = 0;
        int currentCost = 0, previousCost = 0;

        for (int i = 1; i <= n; i++)
        {
            if (colorSequence[i - 1] == previousColor)
            {
                currentCost = previousCost + min(timeRequired[i - 1], previousTime);
                previousTime = max(timeRequired[i - 1], previousTime);
            }
            else
            {
                currentCost = previousCost;
                previousColor = colorSequence[i - 1];
                previousTime = timeRequired[i - 1];
            }
            previousCost = currentCost;
        }

        return previousCost;
    }
};
