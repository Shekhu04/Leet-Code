class Solution {
public:
    bool isHappy(int n) {
        if(n == 1)
            return true;
        if(n > 1 && n <= 4)
            return false;
        int ans=0;
        while(n){
            int a=n%10;
            ans+=pow(a,2);
            n/=10;
        }
        return isHappy(ans);
  
        
    }
};