#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), customCompare);
        return arr;
    }

private:
    static int findWeight(int num)
    {
        int weight = 0;

        while (num > 0)
        {
            weight++;
            num &= (num - 1);
        }

        return weight;
    }

    static bool customCompare(int a, int b)
    {
        if (findWeight(a) == findWeight(b))
            return a < b;

        return findWeight(a) < findWeight(b);
    }
};