#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        stack<pair<int, int>> st_p, st_n;

        vector<int> left(arr.size()), right(arr.size());

        for (int i = 0; i < arr.size(); i++)
        {
            left[i] = i + 1;
            right[i] = arr.size() - i;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            while (!st_p.empty() && st_p.top().first > arr[i])
                st_p.pop();

            left[i] = st_p.empty() ? i + 1 : i - st_p.top().second;
            st_p.push({arr[i], i});

            while (!st_n.empty() && st_n.top().first > arr[i])
            {
                auto x = st_n.top();
                st_n.pop();
                right[x.second] = i - x.second;
            }

            st_n.push({arr[i], i});
        }

        long long ans = 0, mod = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++)
            ans = (ans + static_cast<long long>(arr[i]) * left[i] * right[i]) % mod;
        return static_cast<int>(ans);
    }
};