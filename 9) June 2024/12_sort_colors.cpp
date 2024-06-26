#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1, i = 0;
        while (i <= high)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[low]);
                low++, i++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[high]);
                high--;
            }
            else
                i++;
        }
    }
};