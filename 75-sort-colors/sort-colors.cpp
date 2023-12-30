class Solution {
public:
    void sortColors(vector<int>& nums) {
     
    /*Optimal Approach*/
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
  }
};