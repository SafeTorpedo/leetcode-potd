#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int consumed = 0;

        while (numBottles >= numExchange)
        {
            int newBottles = numBottles / numExchange;

            consumed += numExchange * newBottles;
            numBottles -= numExchange * newBottles;
            numBottles += newBottles;
        }

        return consumed + numBottles;
    }
};