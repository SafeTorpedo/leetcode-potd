#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int required = tickets[k];
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (i <= k)
                ans += min(tickets[k], tickets[i]);
            else
                ans += min(tickets[k] - 1, tickets[i]);
        }

        return ans;
    }
};