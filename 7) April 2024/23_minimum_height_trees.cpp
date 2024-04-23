#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            indegree[u]++;
            indegree[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
                q.push(i);
        }

        int nodes = n;
        while (nodes > 2)
        {
            int size = q.size();
            nodes -= size;

            while (size--)
            {
                int front = q.front();
                q.pop();

                for (int &neighbour : adj[front])
                {
                    indegree[neighbour]--;

                    if (indegree[neighbour] == 1)
                        q.push(neighbour);
                }
            }
        }

        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};