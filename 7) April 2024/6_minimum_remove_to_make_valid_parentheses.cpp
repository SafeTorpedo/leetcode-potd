#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')')
            {
                if (count == 0)
                    s[i] = '#';
                else
                    count--;
            }
        }

        int temp = n - 1;
        while (count != 0)
        {
            if (s[temp] == '(')
            {
                s[temp] = '#';
                count--;
            }

            temp--;
        }

        string ans;
        for (char ch : s)
        {
            if (ch != '#')
                ans.push_back(ch);
        }

        return ans;
    }
};