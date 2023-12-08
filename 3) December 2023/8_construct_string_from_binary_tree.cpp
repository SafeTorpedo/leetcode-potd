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
    string tree2str(TreeNode *root)
    {
        if (root == NULL)
            return "";

        stringstream ans;

        preorder(root, ans);

        return ans.str();
    }

private:
    void preorder(TreeNode *node, stringstream &ans)
    {
        if (node == NULL)
            return;

        ans << node->val;

        if (node->left != NULL || node->right != NULL)
        {
            ans << "(";
            preorder(node->left, ans);
            ans << ")";
        }

        if (node->right != NULL)
        {
            ans << "(";
            preorder(node->right, ans);
            ans << ")";
        }
    }
};