class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start=0,end=n-1;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            if(abs(nums[start])>=abs(nums[end])){
                ans[i] = nums[start]*nums[start];
                start++;
            }else{
                ans[i] = nums[end]*nums[end];
                end--;
            }
        }
        return ans;
    }
};