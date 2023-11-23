#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++)
        {
            vector<int> arr(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.push_back(check(arr));
        }

        return ans;
    }

private:
    bool check(vector<int> &arr)
    {
        int minElement = *min_element(arr.begin(), arr.end());
        int maxElement = *max_element(arr.begin(), arr.end());
        unordered_set<int> arrSet(arr.begin(), arr.end());

        if ((maxElement - minElement) % (arr.size() - 1) != 0)
            return false;

        int diff = (maxElement - minElement) / (arr.size() - 1);
        int curr = minElement + diff;

        while (curr < maxElement)
        {
            if (arrSet.find(curr) == arrSet.end())
                return false;

            curr += diff;
        }

        return true;
    }
};