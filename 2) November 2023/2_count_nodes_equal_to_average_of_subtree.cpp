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
    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }

private:
    pair<int, int> postorder(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return {0, 0};

        auto [leftSum, leftCount] = postorder(root->left, ans);
        auto [rightSum, rightCount] = postorder(root->right, ans);

        int sum = leftSum + rightSum + root->val;
        int count = leftCount + rightCount + 1;

        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }
};