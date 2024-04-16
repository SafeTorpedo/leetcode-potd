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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;

            return newRoot;
        }

        return solve(root, val, depth, 1);
    }

private:
    TreeNode *solve(TreeNode *node, int val, int depth, int curr)
    {
        if (node == NULL)
            return NULL;

        if (curr == depth - 1)
        {
            TreeNode *tempLeft = node->left;
            TreeNode *tempRight = node->right;

            node->left = new TreeNode(val);
            node->right = new TreeNode(val);

            node->left->left = tempLeft;
            node->right->right = tempRight;

            return node;
        }

        node->left = solve(node->left, val, depth, curr + 1);
        node->right = solve(node->right, val, depth, curr + 1);

        return node;
    }
};