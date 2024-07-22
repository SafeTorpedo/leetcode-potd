#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        vector<int> indices(n);
        vector<string> ans(n);
        iota(begin(indices), end(indices), 0);

        auto lambda = [&](int &idx1, int &idx2)
        {
            return heights[idx1] > heights[idx2];
        };

        sort(begin(indices), end(indices), lambda);
        for (int i = 0; i < n; i++)
            ans[i] = names[indices[i]];

        return ans;
    }
};