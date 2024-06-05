#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        int n = words.size();

        vector<int> mp(26, 0);
        vector<int> current(26, 0);
        vector<string> ans;

        for (char &ch : words[0])
            mp[ch - 'a']++;

        for (int i = 1; i < n; i++)
        {
            for (char &ch : words[i])
                current[ch - 'a']++;

            for (int letter = 0; letter < 26; letter++)
                mp[letter] = min(mp[letter], current[letter]);

            fill(current.begin(), current.end(), 0);
        }

        for (int letter = 0; letter < 26; letter++)
        {
            for (int ctr = 0; ctr < mp[letter]; ctr++)
                ans.push_back(string(1, letter + 'a'));
        }

        return ans;
    }
};