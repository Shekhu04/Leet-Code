class Solution {
public:
    int mySqrt(int x) {        
        int start = 1,end=INT_MAX,ans;
        
        while (start <= end) {
            long mid = start +(end-start)/ 2;
            if (mid*mid<=x) {
               ans=mid;
                start=mid+1;
            } else {
               end=mid-1;
            }
        }
        return ans;
    }
};
