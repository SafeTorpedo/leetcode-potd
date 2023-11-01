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
    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> mp;
        dfs(root, mp);

        int maxFreq = 0;
        for (auto &[key, val] : mp)
            maxFreq = max(maxFreq, val);

        vector<int> ans;
        for (auto &[key, val] : mp)
        {
            if (val == maxFreq)
                ans.push_back(key);
        }

        return ans;
    }

private:
    void dfs(TreeNode *node, unordered_map<int, int> &mp)
    {
        if (node == NULL)
            return;

        mp[node->val]++;
        dfs(node->left, mp);
        dfs(node->right, mp);
    }
};