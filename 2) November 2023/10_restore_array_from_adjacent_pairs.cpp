#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> graph;

        for (auto &edge : adjacentPairs)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int root = 0;
        for (auto &pair : graph)
        {
            if (pair.second.size() == 1)
            {
                root = pair.first;
                break;
            }
        }

        vector<int> ans;
        dfs(root, INT_MAX, ans, graph);
        return ans;
    }

private:
    void dfs(int node, int prev, vector<int> &ans, unordered_map<int, vector<int>> &graph)
    {
        ans.push_back(node);

        for (int neighbor : graph[node])
        {
            if (neighbor != prev)
                dfs(neighbor, node, ans, graph);
        }
    }
};