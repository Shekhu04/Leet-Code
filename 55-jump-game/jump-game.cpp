class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //Initially the final position is the last index
        int finalPosition = nums.size()-1;

        //Start with the second last index
        for(int i = nums.size()-2; i >= 0; i--){

            //if we can reach the final position from this index
            //update the final positionn flag
            if(i + nums[i] >= finalPosition){
                finalPosition = i;
            }
        }

        //if we reach the first index, then we can make the jump possible
        return finalPosition == 0;
    }
};