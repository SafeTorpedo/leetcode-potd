#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;

        for (int num : arr)
        {
            mp[num]++;
        }

        priority_queue<int, vector<int>, greater<int>> frequencies;

        for (auto it : mp)
            frequencies.push(it.second);

        int elementsRemoved = 0;

        while (!frequencies.empty())
        {
            elementsRemoved += frequencies.top();

            if (elementsRemoved > k)
            {
                return frequencies.size();
            }
            frequencies.pop();
        }

        return 0;
    }
};