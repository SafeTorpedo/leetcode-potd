#include <bits/stdc++.h>
using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        // Find Peak
        int low = 1, high = n - 2, peak;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            int leftValue = mountainArr.get(mid - 1);
            int midValue = mountainArr.get(mid);
            int rightValue = mountainArr.get(mid + 1);

            if (leftValue < midValue && midValue < rightValue)
                low = mid + 1;
            else if (leftValue > midValue && midValue > rightValue)
                high = mid - 1;
            else
            {
                peak = mid;
                break;
            }
        }

        // Search Left Portion
        low = 0, high = peak;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int value = mountainArr.get(mid);

            if (value < target)
                low = mid + 1;
            else if (value > target)
                high = mid - 1;
            else
                return mid;
        }

        // Search Right Portion
        low = peak, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int value = mountainArr.get(mid);

            if (value > target)
                low = mid + 1;
            else if (value < target)
                high = mid - 1;
            else
                return mid;
        }

        return -1;
    }
};