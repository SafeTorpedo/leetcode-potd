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
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        solve(root, ans, 0);
        return ans;
    }

private:
    void solve(TreeNode *node, int &ans, int currentSum)
    {
        if (node == NULL)
            return;

        currentSum = (currentSum * 10) + node->val;

        if (node->left == NULL && node->right == NULL)
        {
            ans += currentSum;
            return;
        }

        solve(node->left, ans, currentSum);
        solve(node->right, ans, currentSum);
    }
};