#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> m;

        for (int root : arr)
        {
            m[root] = 1;
            for (int factor : arr)
            {
                if (factor >= root)
                    break;

                int temp = root / factor;
                if (root % factor == 0 && m.find(temp) != m.end())
                    m[root] += m[factor] * m[temp];
            }
        }

        long ans = 0;
        for (auto entry : m)
            ans += entry.second;

        return ans % (int)(1e9 + 7);
    }
};