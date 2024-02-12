#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ctr = 0, current;

        for (int i : nums)
        {
            if (ctr == 0)
                current = i;

            if (current == i)
                ctr++;
            else
                ctr--;
        }
        return current;
    }
};