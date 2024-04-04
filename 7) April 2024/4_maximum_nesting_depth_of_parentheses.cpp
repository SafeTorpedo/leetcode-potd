#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0, current = 0;

        for (char c : s)
        {
            if (c == '(')
                current++;
            else if (c == ')')
                current--;

            ans = max(ans, current);
        }

        return ans;
    }
};