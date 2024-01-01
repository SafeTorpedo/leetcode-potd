#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int contentChildren = 0;
        int cookieIndex = 0;

        while (cookieIndex < s.size() && contentChildren < g.size())
        {
            if (s[cookieIndex] >= g[contentChildren])
                contentChildren++;

            cookieIndex++;
        }

        return contentChildren;
    }
};