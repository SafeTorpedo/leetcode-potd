#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int maxElement = *max_element(arr.begin(), arr.end());

        int current = arr[0];
        int streak = 0;

        for (int i = 1; i < arr.size(); i++)
        {
            int opponent = arr[i];

            if (current > opponent)
                streak++;
            else
            {
                current = opponent;
                streak = 1;
            }

            if (streak == k || current == maxElement)
                return current;
        }

        return -1;
    }
};