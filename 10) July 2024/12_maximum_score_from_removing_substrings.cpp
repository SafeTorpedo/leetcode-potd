#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int n = s.size();
        int ans = 0;

        string big = (x > y) ? "ab" : "ba";
        string small = (x < y) ? "ab" : "ba";

        string temp_first = remove(s, big);
        int temp_size = temp_first.size();
        ans += ((n - temp_size) / 2) * max(x, y);

        string temp_second = remove(s, small);
        ans += ((temp_size - temp_second.size()) / 2) * min(x, y);

        return ans;
    }

private:
    string remove(string &s, string &match)
    {
        int i = 0;
        int n = s.size();

        for (int j = 0; j < n; j++)
        {
            s[i] = s[j];
            i++;

            if (i >= 2 && s[i - 2] == match[0] && s[i - 1] == match[1])
                i -= 2;
        }

        s.erase(begin(s) + i, end(s));
        return s;
    }
};