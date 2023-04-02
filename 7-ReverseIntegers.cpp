class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int temp=abs(x);
        int c=abs(x);
        int i=0;
        while(c>0){
            i++;
            c/=10;
        }
        while(temp>0){
            int a=temp%10;
            if((double)INT_MAX/ans<=10.0)
                return 0;
            ans*=10;
            ans+=a;
            temp/=10;
        }
        
        if(x>0) return ans;
        return ans*-1;
    }
};
