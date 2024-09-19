class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        //Longer Prefix match
        for(int i = n-2; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){  //breakout point
                ind = i;
                break;
            }
        }

        //if there is no breakout point
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //find next greater element and swa[]
        for(int i = n-1; i > ind; i--){
            if(nums[i] > nums[ind] ){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        
        //reverse the remaining array
        reverse(nums.begin()+ind+1, nums.end());
    }
};