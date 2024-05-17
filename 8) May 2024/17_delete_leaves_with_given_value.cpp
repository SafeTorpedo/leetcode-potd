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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        stack<TreeNode *> stack;
        TreeNode *currentNode = root, *lastRightNode = nullptr;

        while (!stack.empty() || currentNode != nullptr)
        {
            while (currentNode != nullptr)
            {
                stack.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = stack.top();

            if (currentNode->right != lastRightNode && currentNode->right)
            {
                currentNode = currentNode->right;
                continue;
            }

            stack.pop();

            if (currentNode->right == nullptr && currentNode->left == nullptr && currentNode->val == target)
            {
                if (stack.empty())
                {
                    return nullptr;
                }

                TreeNode *parent = stack.top();

                if (parent->left == currentNode)
                {
                    parent->left = nullptr;
                }
                else
                {
                    parent->right = nullptr;
                }
            }

            lastRightNode = currentNode;
            currentNode = nullptr;
        }
        return root;
    }
};