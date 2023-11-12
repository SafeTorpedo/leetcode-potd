#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> adj;
        for (int route = 0; route < routes.size(); route++)
        {
            for (int stop : routes[route])
                adj[stop].push_back(route);
        }

        queue<int> q;
        unordered_set<int> visited;

        for (int route : adj[source])
        {
            q.push(route);
            visited.insert(route);
        }

        int ans = 1;
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int route = q.front();
                q.pop();

                for (auto stop : routes[route])
                {
                    if (stop == target)
                        return ans;

                    for (auto nextRoute : adj[stop])
                    {
                        if (!visited.count(nextRoute))
                        {
                            visited.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};