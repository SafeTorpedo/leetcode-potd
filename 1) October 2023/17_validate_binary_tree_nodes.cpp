#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        int root = helper(n, leftChild, rightChild);
        if (root == -1)
            return false;

        unordered_set<int> visited;
        stack<int> st;
        visited.insert(root);
        st.push(root);

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children)
            {
                if (child != -1)
                {
                    if (visited.find(child) != visited.end())
                        return false;

                    st.push(child);
                    visited.insert(child);
                }
            }
        }

        return visited.size() == n;
    }

private:
    int helper(int n, vector<int> &left, vector<int> &right)
    {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());

        for (int i = 0; i < n; i++)
        {
            if (children.find(i) == children.end())
                return i;
        }

        return -1;
    }
};