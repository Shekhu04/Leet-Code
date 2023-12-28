class Solution {
    
    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */
    
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, n = nums.size();
        int res = INT_MAX, currSum = 0;
        
        for(end=0; end<n; end++){
            currSum += nums[end];
            
            while(currSum >= target){
                res = min(res, end-start+1);
                
                currSum -= nums[start];
                start++;
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};