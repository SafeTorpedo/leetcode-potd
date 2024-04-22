#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        string start = "0000";

        if (dead.find(start) != dead.end())
            return -1;

        queue<string> q;
        q.push(start);

        int ans = 0;
        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                string curr = q.front();
                q.pop();

                if (curr == target)
                    return ans;

                addNeighbours(q, curr, dead);
            }

            ans++;
        }

        return -1;
    }

private:
    void addNeighbours(queue<string> &q, string &curr, unordered_set<string> &dead)
    {
        for (int i = 0; i < 4; i++)
        {
            char ch = curr[i];

            char dec = ch == '0' ? '9' : ch - 1;
            char inc = ch == '9' ? '0' : ch + 1;

            curr[i] = dec;
            if (dead.find(curr) == dead.end())
            {
                dead.insert(curr);
                q.push(curr);
            }

            curr[i] = inc;
            if (dead.find(curr) == dead.end())
            {
                dead.insert(curr);
                q.push(curr);
            }

            curr[i] = ch;
        }
    }
};