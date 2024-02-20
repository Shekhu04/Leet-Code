class Solution {
public:
    int solve(int left , int right){
        if(left == 0)return 0;
        int bit1 = log2(left);
        int bit2 = log2(right);
        if(bit1 < bit2)return 0;
        return (1<<bit1) | solve((left^(1<<bit1)) , (right^(1<<bit1))); 
    }
    int rangeBitwiseAnd(int left, int right) {
         return solve(left , right);
    }
};