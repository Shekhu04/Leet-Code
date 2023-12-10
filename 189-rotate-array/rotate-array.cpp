class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        //Creating a new array
        vector<int>temp(nums.size());

        for(int i=0; i<nums.size(); i++){
            temp[(i+k)%nums.size()] = nums[i];
        }
        //copying temp into nums
        nums = temp;
    }
};