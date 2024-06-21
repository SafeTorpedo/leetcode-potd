#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int unsatisfied=0;

        for (int i=0; i<minutes; i++)
            unsatisfied+=customers[i]*grumpy[i];

        int maxUnsatisfied=unsatisfied;

        for (int i=minutes; i<n; i++){
            unsatisfied+=customers[i]*grumpy[i];
            unsatisfied-=customers[i-minutes]*grumpy[i-minutes];

            maxUnsatisfied=max(maxUnsatisfied, unsatisfied);
        }

        int ans=maxUnsatisfied;
        for (int i=0; i<n; i++)
            ans+=customers[i]*(1-grumpy[i]);

        return ans;
    }
};