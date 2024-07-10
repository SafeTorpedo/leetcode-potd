#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int count = 0;
        for (auto &log : logs)
        {
            if (log == "../")
            {
                count = count == 0 ? count : count - 1;
            }
            else if (log == "./")
            {
            }
            else
                count++;
        }

        return count;
    }
};