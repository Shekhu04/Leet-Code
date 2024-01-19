class Solution {
private:

    int solveTabulation(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1, INT_MAX);
        dp[0]=0;

        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j] >= 0 && dp[i-coins[j]]!=INT_MAX)
                {
                    int ans = dp[i-coins[j]];
                    dp[i] = min(dp[i], ans+1);

                }
            }
        }

        return dp[amount];
        
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        
        int ans = solveTabulation(coins, amount);

        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
};