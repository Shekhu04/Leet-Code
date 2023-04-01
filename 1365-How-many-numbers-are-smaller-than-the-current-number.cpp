class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int N = nums.size();
        vector<int> sorted = nums;
        vector<int> ans(N);
        
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < nums.size(); i++){
            int ix = find(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            
            ans[i] = ix;
        }
        return ans;
    }
};
