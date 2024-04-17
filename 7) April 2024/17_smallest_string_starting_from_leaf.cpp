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
    string smallestFromLeaf(TreeNode *root)
    {
        string ans = "";
        dfs(root, "", ans);

        return ans;
    }

private:
    void dfs(TreeNode *node, string curr, string &ans)
    {
        if (node == NULL)
            return;

        curr = char(node->val + 'a') + curr;

        if (node->left == NULL && node->right == NULL)
        {
            if (ans == "" || curr < ans)
                ans = curr;

            return;
        }

        dfs(node->left, curr, ans);
        dfs(node->right, curr, ans);
    }
};