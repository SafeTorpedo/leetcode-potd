#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> adj;

        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        return check(adj, source, destination, visited);
    }

private:
    bool check(unordered_map<int, vector<int>> &adj, int source, int dest, vector<bool> &visited)
    {
        if (source == dest)
            return true;

        if (visited[source] == true)
            return false;

        visited[source] = true;

        for (auto &node : adj[source])
        {
            if (check(adj, node, dest, visited))
                return true;
        }

        return false;
    }
};