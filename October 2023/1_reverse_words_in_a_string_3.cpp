#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int left = 0, right = 0;
        int n = s.size();

        while (left < n)
        {
            while (right < n && s[right] != ' ')
                right++;

            reverse(s.begin() + left, s.begin() + right);

            right++;
            left = right;
        }

        return s;
    }
};