#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                prefix[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        vector<int> suffix(n, n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                suffix[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (prefix[i] < k && suffix[i] > k)
                ans = max(ans, nums[i] * (suffix[i] - prefix[i] - 1));
        }

        return ans;
    }
};