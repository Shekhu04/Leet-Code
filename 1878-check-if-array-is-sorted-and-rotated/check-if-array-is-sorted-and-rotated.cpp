class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), count = 0, temp;
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                count++;
            }
            if(count > 1){
              return false;
            }
        }

        if(count == 1 && nums[0] < nums[n-1]){
          return false;
        }

        return true;
    }
};