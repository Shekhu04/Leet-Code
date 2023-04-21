class Solution {
public:
    bool isPowerOfFour(int x) {
        if(x==1)
            return true;
        if(x==0 || x%4 != 0){
            return false;
        }
        return isPowerOfFour(x/4);
    }
};
