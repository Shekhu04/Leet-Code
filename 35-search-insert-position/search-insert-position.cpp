class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int n = nums.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high-low) / 2;
        // maybe an answer
        if (nums[mid] >= target) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
    }
};