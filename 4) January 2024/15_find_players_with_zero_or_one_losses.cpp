#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> lost;

        for (int i = 0; i < matches.size(); i++)
        {
            int loss = matches[i][1];
            lost[loss]++;
        }

        vector<int> notLost;
        vector<int> onceLost;

        for (int i = 0; i < matches.size(); i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if (lost.find(winner) == lost.end())
            {
                notLost.push_back(winner);
                lost[winner] = 2;
            }

            if (lost[loser] == 1)
                onceLost.push_back(loser);
        }

        sort(notLost.begin(), notLost.end());
        sort(onceLost.begin(), onceLost.end());

        return {notLost, onceLost};
    }
};