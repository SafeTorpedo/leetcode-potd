#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        priority_queue<float, vector<float>, greater<float>> time;

        for (int i = 0; i < dist.size(); i++)
            time.push((float)dist[i] / speed[i]);

        int ans = 0;
        while (!time.empty())
        {
            if (time.top() <= ans)
                break;

            ans++;
            time.pop();
        }

        return ans;
    }
};