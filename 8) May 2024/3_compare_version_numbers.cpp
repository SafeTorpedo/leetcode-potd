#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<string> tokens1 = getTokens(version1);
        vector<string> tokens2 = getTokens(version2);

        int m = tokens1.size();
        int n = tokens2.size();

        int i = 0;
        while (i < m || i < n)
        {
            int a = i < m ? stoi(tokens1[i]) : 0;
            int b = i < n ? stoi(tokens2[i]) : 0;

            if (a < b)
                return -1;
            else if (a > b)
                return 1;

            i++;
        }

        return 0;
    }

private:
    vector<string> getTokens(string version)
    {
        vector<string> ans;
        stringstream ss(version);
        string token = "";

        while (getline(ss, token, '.'))
            ans.push_back(token);

        return ans;
    }
};