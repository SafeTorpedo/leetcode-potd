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
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int ans = 0;
        preorder(root, 0, ans);
        return ans;
    }

private:
    void preorder(TreeNode *node, int count, int &ans)
    {
        if (node == NULL)
            return;

        count ^= (1 << node->val);

        if (!node->left && !node->right)
            ans += (count & (count - 1)) == 0;

        preorder(node->left, count, ans);
        preorder(node->right, count, ans);
    }
};