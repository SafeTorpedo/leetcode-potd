#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        const int MOD = 1e9 + 7;

        long count = 1;
        int seats = 0;
        int previousPairLast = -1;

        for (int i = 0; i < corridor.size(); i++)
        {
            if (corridor[i] == 'S')
            {
                seats++;

                if (seats == 2)
                {
                    previousPairLast = i;
                    seats = 0;
                }
                else if (seats == 1 && previousPairLast != -1)
                {
                    count *= (i - previousPairLast);
                    count %= MOD;
                }
            }
        }

        if (seats == 1 || previousPairLast == -1)
            return 0;

        return (int)count;
    }
};