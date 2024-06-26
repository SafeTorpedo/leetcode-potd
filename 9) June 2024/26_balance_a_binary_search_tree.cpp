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
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> vec;
        inorder(root, vec);

        int l = 0, r = vec.size() - 1;
        return constructBST(l, r, vec);
    }

private:
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }

    TreeNode *constructBST(int l, int r, vector<int> &vec)
    {
        if (l > r)
            return NULL;

        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(vec[mid]);
        root->left = constructBST(l, mid - 1, vec);
        root->right = constructBST(mid + 1, r, vec);

        return root;
    }
};