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
    int maxAncestorDiff(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    pair<int, int> dfs(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return {INT_MAX, INT_MIN};

        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);

        int minVal = min(root->val, min(left.first, right.first));
        int maxVal = max(root->val, max(left.second, right.second));

        ans = max({ans, abs(minVal - root->val), abs(maxVal - root->val)});

        return {minVal, maxVal};
    }
};