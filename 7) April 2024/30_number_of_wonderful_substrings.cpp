#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        unordered_map<long long, long long> mp;

        mp[0] = 1;
        int cumXor = 0;
        long long ans = 0;

        for (char &ch : word)
        {
            int shift = ch - 'a';
            cumXor ^= (1 << shift);

            ans += mp[cumXor];

            for (char ch1 = 'a'; ch1 <= 'j'; ch1++)
            {
                shift = ch1 - 'a';
                int checkXor = (cumXor ^ (1 << shift));

                ans += mp[checkXor];
            }

            mp[cumXor]++;
        }

        return ans;
    }
};