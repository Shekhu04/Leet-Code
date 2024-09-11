class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0; //first unique element

        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){ //Checking for next unique number

                nums[i+1] = nums[j]; //If unique number id found then place it just after i

                i++; //increment i to check for future unique element
            }
        }
        return i+1;
    }
};