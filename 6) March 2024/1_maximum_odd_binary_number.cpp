#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        const int n = s.length();

        int count = 0;
        for (char &c : s)
        {
            count += c - '0';
        }

        string result = "";
        for (int i = 0; i < count - 1; i++)
        {
            result += "1";
        }
        for (int i = 0; i < n - count; i++)
        {
            result += "0";
        }
        result += "1";
        return result;
    }
};