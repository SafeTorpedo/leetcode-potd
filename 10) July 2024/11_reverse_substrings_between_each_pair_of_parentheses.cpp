#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        int n = s.length();
        stack<int> indices;
        vector<int> mp(n);

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                indices.push(i);
            }
            if (s[i] == ')')
            {
                int j = indices.top();
                indices.pop();
                mp[i] = j;
                mp[j] = i;
            }
        }

        string result;
        for (int currIndex = 0, direction = 1; currIndex < n; currIndex += direction)
        {
            if (s[currIndex] == '(' || s[currIndex] == ')')
            {
                currIndex = mp[currIndex];
                direction = -direction;
            }
            else
            {
                result += s[currIndex];
            }
        }
        return result;
    }
};