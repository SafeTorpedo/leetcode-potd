#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto a : nums2)
            if (m.count(a))
            {
                ans.push_back(a);
                m.erase(a);
            }
        return ans;
    }
};