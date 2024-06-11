#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> mp;
        vector<int> ans, rem;
        int m = arr1.size(), n = arr2.size();

        for (int i = 0; i < n; i++)
            mp[arr2[i]] = 0;

        for (int i = 0; i < arr1.size(); i++)
        {
            if (mp.find(arr1[i]) != mp.end())
                mp[arr1[i]]++;
            else
                rem.push_back(arr1[i]);
        }

        sort(rem.begin(), rem.end());

        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < mp[arr2[i]]; j++)
                ans.push_back(arr2[i]);
        }

        int o = rem.size();
        for (int i = 0; i < o; i++)
            ans.push_back(rem[i]);

        return ans;
    }
};