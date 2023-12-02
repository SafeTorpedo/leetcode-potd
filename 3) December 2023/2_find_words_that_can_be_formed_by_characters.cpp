#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> counts(26, 0);

        for (char ch : chars)
            counts[ch - 'a']++;

        int ans = 0;
        for (string word : words)
        {
            vector<int> wordCount(26, 0);
            for (char ch : word)
                wordCount[ch - 'a']++;

            bool good = true;
            for (int i = 0; i < 26; i++)
            {
                if (counts[i] < wordCount[i])
                {
                    good = false;
                    break;
                }
            }

            if (good)
                ans += word.size();
        }

        return ans;
    }
};