#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        int m=worker.size();

        vector <pair<int, int>> jobs;
        for (int i=0; i<n; i++)
            jobs.push_back({difficulty[i], profit[i]});

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int j=0;
        int maxProfit=0, ans=0;
        for (int i=0; i<m; i++){
            while (j<n && worker[i]>=jobs[j].first){
                maxProfit=max(maxProfit, jobs[j].second);
                j++;
            }

            ans+=maxProfit;
        }

        return ans;
    }
};