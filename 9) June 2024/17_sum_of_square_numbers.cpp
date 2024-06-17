#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=0, right=sqrt(c);
        
        while (left<=right){
            long long total = left*left + right*right;
            if (total==c)
                return true;
            else if (total<c)
                left++;
            else
                right--;
        }

        return false;
    }
};