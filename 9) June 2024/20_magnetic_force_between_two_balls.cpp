#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int n=position.size();
        int low=1;
        int high=ceil(position[n-1]/(m-1.0));
        int ans=0;

        while (low<=high){
            int mid=low + (high-low)/2;
            if (helper(mid, position, m)){
                ans=mid;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }

        return ans;
    }

private:
    bool helper(int mid, vector<int>& position, int m){
        int prev=position[0];
        int n=position.size();
        int balls=1;

        for (int i=1; i<n && balls<m ; i++){
            int curr=position[i];

            if (curr-prev>=mid){
                balls++;
                prev=curr;
            }
        }

        return balls==m;
    }
};