#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (char ch : s)
            mp[ch]++;

        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
            pq.push({it.second, it.first});

        string ans;
        while (!pq.empty())
        {
            pair<int, char> current = pq.top();
            pq.pop();
            ans.append(current.first, current.second);
        }

        return ans;
    }
};