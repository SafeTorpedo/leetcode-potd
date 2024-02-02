#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i=1; i<=9; i++)
            dfs(low, high, i, 0, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }

private:
    void dfs(int low, int high, int i, int num, vector<int>& ans){
        if (num>=low && num<=high)
            ans.push_back(num);

        if (num>high || i>9)
            return;

        dfs(low, high, i+1, num*10+i, ans);
    }
};