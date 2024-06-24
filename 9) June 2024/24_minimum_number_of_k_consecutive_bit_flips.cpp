#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0, flipCount=0;
        vector <bool> isFlipped(n, false);

        for (int i=0; i<n; i++){
            if (i>=k && isFlipped[i-k]==true)
                flipCount--;

            if (flipCount%2==nums[i]){
                if (i+k>n)
                    return -1;

                flipCount++;
                ans++;
                isFlipped[i]=true;
            }
        }

        return ans;
    }
};