#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    Graph(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        for (auto &edge : edges)
            adj[edge[0]].push_back({edge[1], edge[2]});
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        int n = adj.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> cost(n, INT_MAX);
        cost[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty())
        {
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();

            if (currCost > cost[currNode])
                continue;

            if (currNode == node2)
                return currCost;

            for (auto &neighbor : adj[currNode])
            {
                int neighborNode = neighbor.first;
                int neighborCost = neighbor.second;
                int newCost = currCost + neighborCost;

                if (newCost < cost[neighborNode])
                {
                    cost[neighborNode] = newCost;
                    pq.push({newCost, neighborNode});
                }
            }
        }

        return -1;
    }

private:
    vector<vector<pair<int, int>>> adj;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */