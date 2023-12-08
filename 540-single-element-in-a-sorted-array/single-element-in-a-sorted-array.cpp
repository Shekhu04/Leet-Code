class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        //edge cases
        if (n==1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1, high = n-1;

        while (low <= high){
            int mid = low + (high-low)/2;

            //if mid is the single element
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            //we are in th left 
            if((mid%2 == 0) && nums[mid] == nums[mid+1] || (mid%2 == 1) && nums[mid] == nums[mid-1]){
                //eliminate left half
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return -1;
        
    }
};