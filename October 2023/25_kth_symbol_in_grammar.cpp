#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        return dfs(n, k, 0);
    }

private:
    int dfs(int n, int k, int root)
    {
        if (n == 1)
            return root;

        int nodes = pow(2, n - 1);

        if (k > nodes / 2)
        {
            int next = (root == 0) ? 1 : 0;
            return dfs(n - 1, k - (nodes / 2), next);
        }
        else
        {
            int next = (root == 0) ? 0 : 1;
            return dfs(n - 1, k, next);
        }
    }
};