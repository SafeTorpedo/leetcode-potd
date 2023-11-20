#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        vector<int> prefixSum(travel.size() + 1, 0);
        prefixSum[1] = travel[0];

        for (int i = 1; i < travel.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + travel[i];

        unordered_map<char, int> mp;
        unordered_map<char, int> count;

        for (int i = 0; i < garbage.size(); i++)
        {
            for (char ch : garbage[i])
            {
                mp[ch] = i;
                count[ch]++;
            }
        }

        char types[3] = {'M', 'P', 'G'};
        int ans = 0;
        for (char ch : types)
        {
            if (count[ch] >= 1)
                ans += prefixSum[mp[ch]] + count[ch];
        }

        return ans;
    }
};