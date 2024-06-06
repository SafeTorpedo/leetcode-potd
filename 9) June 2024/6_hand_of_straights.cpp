#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> mp;
        for (int card : hand)
            mp[card]++;

        for (int card : hand)
        {
            int start = card;

            while (mp[start - 1])
                start--;

            while (start <= card)
            {
                while (mp[start])
                {
                    for (int next = start; next < start + groupSize; next++)
                    {
                        if (!mp[next])
                            return false;

                        mp[next]--;
                    }
                }

                start++;
            }
        }

        return true;
    }
};