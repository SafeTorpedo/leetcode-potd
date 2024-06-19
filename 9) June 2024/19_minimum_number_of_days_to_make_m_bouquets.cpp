#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if ((long long)m*(long long)k > n)
            return -1;

        int minDays=*min_element(bloomDay.begin(), bloomDay.end());
        int maxDays=*max_element(bloomDay.begin(), bloomDay.end());

        int low=minDays, high=maxDays, ans=INT_MAX;
        while (low<=high){
            int mid=(low+high)/2;
            
            if (helper(bloomDay, mid, m, k)){
                ans=min(ans, mid);
                high=mid-1;
            } else
                low=mid+1;
        }

        return ans;
    }

private:
    bool helper(vector<int>& bloomDay, int day, int m, int k){
        int n=bloomDay.size();
        int ctr=0, bouquets=0;

        for (int i=0; i<n; i++){
            if (bloomDay[i]<=day)
                ctr++;
            else {
                bouquets+=ctr/k;
                ctr=0;
            }
        }

        bouquets+=ctr/k;
        return bouquets>=m;
    }
};