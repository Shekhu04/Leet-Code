class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        //start with index 1 and compare the price
        //with previous day price to calculate profit if any

        for(int i = 1; i<n; i++){
            if(prices[i] > prices[i-1])
                profit += (prices[i] - prices[i-1]);
        }
        return profit;
    }
};