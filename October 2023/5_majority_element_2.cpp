#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int ctr1 = 0, ctr2 = 0, el1 = INT_MIN, el2 = INT_MIN;
        for (int i : nums)
        {
            if (el1 == i)
                ctr1++;
            else if (el2 == i)
                ctr2++;
            else if (ctr1 == 0)
            {
                el1 = i;
                ctr1 = 1;
            }
            else if (ctr2 == 0)
            {
                el2 = i;
                ctr2 = 1;
            }
            else
            {
                ctr1--;
                ctr2--;
            }
        }

        vector<int> ans;
        int req = nums.size() / 3;
        ctr1 = 0, ctr2 = 0;
        for (int i : nums)
        {
            if (i == el1)
                ctr1++;
            if (i == el2)
                ctr2++;
        }
        if (ctr1 > req)
            ans.push_back(el1);
        if (ctr2 > req)
            ans.push_back(el2);

        return ans;
    }
};