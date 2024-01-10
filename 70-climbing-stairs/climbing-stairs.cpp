class Solution {
private:
   int solve(int n){
     vector<int>dp(n+1);

     //Base Case 
     dp[0]=1;
     dp[1]=1;

     for(int i=2;i<=n;i++){
         dp[i]=dp[i-1]+dp[i-2];
     }
     return dp[n];

   }
public:
    int climbStairs(int n) {
        int answer=solve(n);
        return answer;
    }
};