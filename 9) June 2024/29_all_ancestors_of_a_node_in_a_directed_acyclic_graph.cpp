#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjacencyList(n);
        vector<vector<int>> ancestors(n);

        for (vector<int> edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
        }

        for (int i = 0; i < n; i++)
        {
            findAncestorsDFS(i, adjacencyList, i, ancestors);
        }

        return ancestors;
    }

private:
    void findAncestorsDFS(int ancestor, vector<vector<int>> &adjacencyList, int currentNode, vector<vector<int>> &ancestors)
    {
        for (int childNode : adjacencyList[currentNode])
        {
            if (ancestors[childNode].empty() || ancestors[childNode].back() != ancestor)
            {
                ancestors[childNode].push_back(ancestor);
                findAncestorsDFS(ancestor, adjacencyList, childNode, ancestors);
            }
        }
    }
};