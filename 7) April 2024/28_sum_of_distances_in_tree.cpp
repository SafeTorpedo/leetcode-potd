#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        N = n;
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> count(n, 0);

        dfsRoot(adj, count, 0, -1, 0);

        vector<int> ans(n, 0);
        ans[0] = rootAns;

        dfsAns(adj, count, ans, 0, -1);

        return ans;
    }

private:
    long rootAns = 0;
    int N;

    int dfsRoot(unordered_map<int, vector<int>> &adj, vector<int> &count, int curr, int parent, int depth)
    {
        rootAns += depth;
        int nodeCount = 1;

        for (int &child : adj[curr])
        {
            if (child == parent)
                continue;

            nodeCount += dfsRoot(adj, count, child, curr, depth + 1);
        }

        count[curr] = nodeCount;

        return nodeCount;
    }

    void dfsAns(unordered_map<int, vector<int>> &adj, vector<int> &count, vector<int> &ans, int curr, int parent)
    {
        for (int &child : adj[curr])
        {
            if (child == parent)
                continue;

            ans[child] = ans[curr] - count[child] + (N - count[child]);

            dfsAns(adj, count, ans, child, curr);
        }
    }
};