#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int count = 0;
        int mid = s.length() / 2;

        for (int i = 0; i < mid; i++)
        {
            char a = s[i];
            char b = s[mid + i];

            if (vowels.count(a) >= 1)
                count++;

            if (vowels.count(b) >= 1)
                count--;
        }

        return count == 0;
    }
};