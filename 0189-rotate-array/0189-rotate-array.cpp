class Solution {
public:
     // Function to reverse the array between start and end indices
    void reverseArray(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    // Function to rotate the array
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // In case k is greater than the size of the array

        // Reverse the entire array
        reverseArray(nums, 0, n-1);

        // Reverse the first k elements
        reverseArray(nums, 0, k-1);

        // Reverse the remaining n-k elements
        reverseArray(nums, k, n-1);
    }
};