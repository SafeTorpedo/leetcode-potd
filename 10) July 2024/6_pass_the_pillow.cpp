#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int direction = time / (n - 1);
        int offset = time % (n - 1);

        if (direction % 2 == 0)
            return offset + 1;

        return n - offset;
    }
};