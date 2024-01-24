class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n>=5){
            int quotient = n/5;
            n = n/5;
            ans+=quotient;
        }
        return ans;
    }
};