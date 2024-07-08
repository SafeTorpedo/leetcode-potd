#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        int ans = helper(n, k) + 1;
        return ans;
    }

private:
    int helper(int n, int k)
    {
        if (n == 1)
            return 0;

        int idx = helper(n - 1, k);
        idx = (idx + k) % n;
        return idx;
    }
};