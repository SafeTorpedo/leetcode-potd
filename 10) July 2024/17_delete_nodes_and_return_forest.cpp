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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> deleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode *> forest;

        root = processNode(root, deleteSet, forest);

        if (root)
        {
            forest.push_back(root);
        }

        return forest;
    }

private:
    TreeNode *processNode(TreeNode *node, unordered_set<int> &deleteSet, vector<TreeNode *> &forest)
    {
        if (!node)
        {
            return NULL;
        }

        node->left = processNode(node->left, deleteSet, forest);
        node->right = processNode(node->right, deleteSet, forest);

        if (deleteSet.find(node->val) != deleteSet.end())
        {
            if (node->left)
            {
                forest.push_back(node->left);
            }
            if (node->right)
            {
                forest.push_back(node->right);
            }
            delete node;
            return NULL;
        }

        return node;
    }
};