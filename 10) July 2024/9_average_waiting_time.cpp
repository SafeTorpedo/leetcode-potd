#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int nextIdle = 0, n = customers.size();
        long long wait = 0;

        for (int i = 0; i < n; i++)
        {
            nextIdle = max(customers[i][0], nextIdle) + customers[i][1];

            wait += (nextIdle - customers[i][0]);
        }

        double ans = (double)wait / n;
        return ans;
    }
};