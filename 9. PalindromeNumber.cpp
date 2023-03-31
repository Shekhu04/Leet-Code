class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        long int reverse=0,num=x;
        while(x!=0){
            int a=x%10;
            reverse=reverse*10+a;
            x=x/10;
        }
        if (num==reverse)
            return true;
        else
            return false;
    }
};
