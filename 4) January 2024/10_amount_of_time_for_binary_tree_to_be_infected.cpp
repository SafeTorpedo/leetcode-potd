#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        dfs(root, start);
        return ans;
    }

private:
    int ans = 0;

    int dfs(TreeNode *root, int start)
    {
        int depth = 0;

        if (root == NULL)
            return depth;

        int left = dfs(root->left, start);
        int right = dfs(root->right, start);

        if (root->val == start)
        {
            ans = max(left, right);
            depth = -1;
        }
        else if (left >= 0 && right >= 0)
            depth = max(left, right) + 1;
        else
        {
            int distance = abs(left) + abs(right);
            ans = max(ans, distance);
            depth = min(left, right) - 1;
        }

        return depth;
    }
};