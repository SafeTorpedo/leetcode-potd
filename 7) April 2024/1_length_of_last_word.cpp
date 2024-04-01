#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size(), tail = n - 1;
        int ans = 0;

        while (tail >= 0)
        {
            if (s[tail] != ' ')
                break;

            tail--;
        }

        while (tail >= 0)
        {
            if (s[tail] == ' ')
                break;

            ans++;
            tail--;
        }

        return ans;
    }
};